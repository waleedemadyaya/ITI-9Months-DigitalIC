ENTITY and2 IS 
    PORT(
        a , b : IN bit;
        c     : OUT bit
    );
END ENTITY and2;

ARCHITECTURE behavioral_and2_senstivity_list OF and2 IS 

BEGIN
    p1: PROCESS (a , b) IS

    BEGIN
        c <= a AND b;
        --WAIT ON a , b;
    END PROCESS p1;
END ARCHITECTURE behavioral_and2_senstivity_list;

ARCHITECTURE behavioral_and2_wait_statement OF and2 IS 

BEGIN
    p1: PROCESS IS --(a , b) 

    BEGIN
        c <= a AND b;
        WAIT ON a , b;
    END PROCESS p1;
END ARCHITECTURE behavioral_and2_wait_statement;