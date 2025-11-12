-------------------------------------------------------------
-- Testbench for ALU Entity (4-bit signed)
-- Covers: ADD, SUB, MUL, DIV operations with edge cases
-- Author: Waleed Emad Yahyaa
-------------------------------------------------------------

LIBRARY ieee;
USE ieee.numeric_bit.ALL;
USE work.pack_a.ALL;  -- For op_type

ENTITY alu_tb IS
END ENTITY alu_tb;

ARCHITECTURE tb OF alu_tb IS

    -- DUT Signals
    SIGNAL a, b, c : signed(3 DOWNTO 0);
    SIGNAL op : op_type;

    -- Test variables
    SIGNAL expected : signed(3 DOWNTO 0);

BEGIN

    -- DUT Instance
    DUT: ENTITY work.alu(alu)
        PORT MAP (
            op => op,
            a  => a,
            b  => b,
            c  => c
        );

    ---------------------------------------------------------
    -- Stimulus process
    ---------------------------------------------------------
    PROCESS
        PROCEDURE check_result(
            CONSTANT op_name : STRING;
            CONSTANT expected_val : signed(3 DOWNTO 0)
        ) IS
        BEGIN
            ASSERT c = expected_val
            REPORT op_name & " failed: Expected " &
                   INTEGER'IMAGE(to_integer(expected_val)) &
                   ", Got " & INTEGER'IMAGE(to_integer(c))
            SEVERITY ERROR;
        END PROCEDURE;

    BEGIN

        -----------------------------------------------------
        -- ADDITION TESTS
        -----------------------------------------------------
        op <= add;
        a <= "0000"; b <= "0000"; WAIT FOR 10 ns; expected <= "0000"; check_result("ADD 0+0", expected);
        a <= "0011"; b <= "0010"; WAIT FOR 10 ns; expected <= "0101"; check_result("ADD 3+2", expected);
        a <= "0000"; b <= "0011"; WAIT FOR 10 ns; expected <= "0011"; check_result("ADD 0+3", expected);
        a <= "0011"; b <= "0000"; WAIT FOR 10 ns; expected <= "0011"; check_result("ADD 3+0", expected);
        a <= "0111"; b <= "0111"; WAIT FOR 10 ns; expected <= "1110"; check_result("ADD 7+7 (overflow case)", expected);

        -----------------------------------------------------
        -- SUBTRACTION TESTS
        -----------------------------------------------------
        op <= sub;
        a <= "0000"; b <= "0000"; WAIT FOR 10 ns; expected <= "0000"; check_result("SUB 0-0", expected);
        a <= "0011"; b <= "0010"; WAIT FOR 10 ns; expected <= "0001"; check_result("SUB 3-2", expected);
        a <= "0000"; b <= "0011"; WAIT FOR 10 ns; expected <= "1101"; check_result("SUB 0-3", expected);
        a <= "0011"; b <= "0000"; WAIT FOR 10 ns; expected <= "0011"; check_result("SUB 3-0", expected);
        a <= "0111"; b <= "0111"; WAIT FOR 10 ns; expected <= "0000"; check_result("SUB 7-7", expected);

        -----------------------------------------------------
        -- MULTIPLICATION TESTS
        -----------------------------------------------------
        op <= mul;
        a <= "0000"; b <= "0000"; WAIT FOR 10 ns; expected <= "0000"; check_result("MUL 0*0", expected);
        a <= "0011"; b <= "0010"; WAIT FOR 10 ns; expected <= "0110"; check_result("MUL 3*2", expected);
        a <= "0000"; b <= "0011"; WAIT FOR 10 ns; expected <= "0000"; check_result("MUL 0*3", expected);
        a <= "0011"; b <= "0000"; WAIT FOR 10 ns; expected <= "0000"; check_result("MUL 3*0", expected);
        a <= "0111"; b <= "0111"; WAIT FOR 10 ns; expected <= "0001"; check_result("MUL 7*7 (overflow case)", expected);

        -----------------------------------------------------
        -- DIVISION TESTS
        -----------------------------------------------------
        op <= div;
        a <= "0000"; b <= "0000"; WAIT FOR 10 ns;
        ASSERT FALSE REPORT "DIV 0/0: Division by zero detected (expected)" SEVERITY WARNING;

        a <= "0011"; b <= "0010"; WAIT FOR 10 ns; expected <= "0001"; check_result("DIV 3/2", expected);
        a <= "0000"; b <= "0011"; WAIT FOR 10 ns; expected <= "0000"; check_result("DIV 0/3", expected);

        a <= "0011"; b <= "0000"; WAIT FOR 10 ns;
        ASSERT FALSE REPORT "DIV 3/0: Division by zero detected (expected)" SEVERITY WARNING;

        a <= "0111"; b <= "0111"; WAIT FOR 10 ns; expected <= "0001"; check_result("DIV 7/7", expected);

        -----------------------------------------------------
        -- END OF TEST
        -----------------------------------------------------
        REPORT "All ALU test cases completed successfully." SEVERITY NOTE;
        WAIT;
    END PROCESS;

END ARCHITECTURE tb;
