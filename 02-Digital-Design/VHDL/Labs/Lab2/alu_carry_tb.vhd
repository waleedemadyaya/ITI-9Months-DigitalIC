------------------------------------------------------------
-- Testbench for alu_variable
-- Author   : Waleed Emad Yahyaa
-- Purpose  : Functional verification of arithmetic operations
-- Features : Self-checking with assertions and coverage of edge cases
------------------------------------------------------------

LIBRARY ieee;
USE ieee.numeric_bit.ALL;
USE std.textio.ALL;

ENTITY tb_alu_variable IS
END ENTITY;

ARCHITECTURE behavior OF tb_alu_variable IS
  CONSTANT width : positive := 8;

  SIGNAL a, b, c_exp, c_out : signed(width-1 DOWNTO 0);
  SIGNAL control : unsigned(1 DOWNTO 0);

  -- DUT Instantiation
  COMPONENT alu_variable IS
    GENERIC( width: positive := 8);
    PORT(
      a, b    : IN signed(width-1 DOWNTO 0);
      control : IN unsigned(1 DOWNTO 0);
      c       : OUT signed(width-1 DOWNTO 0)
    );
  END COMPONENT;

BEGIN
  DUT: alu_variable
    GENERIC MAP(width => width)
    PORT MAP(
      a => a,
      b => b,
      control => control,
      c => c_out
    );

  -------------------------------------------------------------------
  -- Stimulus process
  -------------------------------------------------------------------
  stim_proc: PROCESS
    -- Local helper procedure for compact checking
    PROCEDURE check_operation(
      CONSTANT op_name : IN string;
      CONSTANT op_ctrl : IN unsigned(1 DOWNTO 0);
      CONSTANT val_a, val_b : IN signed(width-1 DOWNTO 0)
    ) IS
      VARIABLE temp   : signed(2*width - 1 DOWNTO 0);
      VARIABLE result : signed(width-1 DOWNTO 0);
    BEGIN
      a <= val_a;
      b <= val_b;
      control <= op_ctrl;
      WAIT FOR 10 ns;

      CASE op_ctrl IS
        WHEN "00" => result := val_a + val_b;
        WHEN "01" => result := val_a - val_b;
        WHEN "10" =>
          temp := val_a * val_b;
          result := temp(width-1 DOWNTO 0);
        WHEN "11" =>
          IF val_b /= 0 THEN
            result := val_a / val_b;
          ELSE
            result := (OTHERS => '0');
          END IF;
        WHEN OTHERS =>
          result := (OTHERS => '0');
      END CASE;

      ASSERT c_out = result
        REPORT op_name & " failed: Expected " &
               integer'image(to_integer(result)) &
               ", Got " &
               integer'image(to_integer(c_out)) &
               " (a=" & integer'image(to_integer(val_a)) &
               ", b=" & integer'image(to_integer(val_b)) & ")"
        SEVERITY ERROR;

      REPORT op_name & " passed for a=" &
             integer'image(to_integer(val_a)) &
             ", b=" & integer'image(to_integer(val_b));
    END PROCEDURE;

  BEGIN
    REPORT "===================================================";
    REPORT " Starting ALU Variable Testbench ";
    REPORT "===================================================";

    -- Test ADD operation
    check_operation("ADD", "00", to_signed(5, width), to_signed(3, width));
    check_operation("ADD", "00", to_signed(-10, width), to_signed(20, width));
    check_operation("ADD", "00", to_signed(100, width), to_signed(50, width));  -- overflow edge
    check_operation("ADD", "00", to_signed(0, width), to_signed(0, width));

    -- Test SUB operation
    check_operation("SUB", "01", to_signed(15, width), to_signed(5, width));
    check_operation("SUB", "01", to_signed(-10, width), to_signed(-5, width));
    check_operation("SUB", "01", to_signed(0, width), to_signed(10, width));

    -- Test MUL operation
    check_operation("MUL", "10", to_signed(3, width), to_signed(4, width));
    check_operation("MUL", "10", to_signed(-3, width), to_signed(4, width));
    check_operation("MUL", "10", to_signed(10, width), to_signed(10, width));

    -- Test DIV operation
    check_operation("DIV", "11", to_signed(20, width), to_signed(4, width));
    check_operation("DIV", "11", to_signed(-20, width), to_signed(5, width));
    check_operation("DIV", "11", to_signed(0, width), to_signed(3, width));
    check_operation("DIV", "11", to_signed(10, width), to_signed(0, width)); -- divide-by-zero edge case

    REPORT "===================================================";
    REPORT " All ALU tests completed ";
    REPORT "===================================================";

    WAIT;
  END PROCESS;
END ARCHITECTURE behavior;

