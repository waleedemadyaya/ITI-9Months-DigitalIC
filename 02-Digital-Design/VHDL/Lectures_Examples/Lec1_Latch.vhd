ENTITY latch IS 
    PORT (
        d , clk : IN bit ;
        q , nq : OUT bit
    );
END ENTITY latch;

ARCHITECTURE behavioral_latch OF latch IS 
SIGNAL q_int : bit;
BEGIN
    p1 : PROCESS (d , clk) IS 
    BEGIN
        -- q_int <= '0';
        IF clk = '1' THEN
            q_int <= d;
        END IF;
    END PROCESS p1;

    q <= q_int;
    nq <= NOT q_int;

--    p2 : PROCESS IS 
--
--    BEGIN
--        IF clk = '1' THEN
--            q <= d;       leads to multi driven signals 
--            nq <= NOT(d);
--        END IF;
--        WAIT ON d , clk;
--    END PROCESS p2;

END ARCHITECTURE behavioral_latch;

--  ARCHITECTURE behavioral_latch_wait_statment OF latch IS 
--  
--  BEGIN
--      p1 : PROCESS IS 
--  
--      BEGIN
--          IF clk = '1' THEN
--              q <= d;
--              nq <= NOT(d);
--          END IF;
--          WAIT ON d , clk;
--      END PROCESS p1;
--  END ARCHITECTURE behavioral_latch_wait_statment;