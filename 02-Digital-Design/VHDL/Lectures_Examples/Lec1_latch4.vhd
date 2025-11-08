ENTITY latch_4 IS 
    PORT (
        d : IN bit_vector (3 DOWNTO 0);
        clk , en : IN bit;
        q : OUT bit_vector (3 DOWNTO 0)
    );
END ENTITY latch_4;

ARCHITECTURE architectural_latch4 OF latch_4 IS

    COMPONENT latch IS 
        PORT (
            d , clk : IN bit ;
            q , nq : OUT bit
        );
    END COMPONENT latch;

    SIGNAL clk_int : bit ;

    FOR ALL: latch USE ENTITY work.latch(behavioral_latch);
BEGIN

    clk_int <= clk AND en;

    latch0 : latch
        PORT MAP ( d => d(0) , clk => clk_int , q => q(0) , nq => OPEN);

    latch1 : latch
        PORT MAP (d(1) , clk_int , q(1));

    latch2 : latch
        PORT MAP (d(2) , clk_int , q(2));

    latch3 : latch
        PORT MAP (d(3) , clk_int , q(3));
    
END ARCHITECTURE architectural_latch4;

--------------------------------------------------------------------------------------------------------
--====================================================================================================--
--------------------------------------------------------------------------------------------------------

ARCHITECTURE behavioral_latch4 OF latch_4 IS 
----------------------------------------------
-- Declarative part
----------------------------------------------
BEGIN
    latch4_process : PROCESS IS
    VARIABLE X : bit_vector (3 DOWNTO 0);
    BEGIN
        IF clk = '1' AND en = '1' THEN
            x := d;
        END IF;
        q <= x;
        WAIT ON d , clk , en;
    END PROCESS latch4_process;
END ARCHITECTURE behavioral_latch4 ;