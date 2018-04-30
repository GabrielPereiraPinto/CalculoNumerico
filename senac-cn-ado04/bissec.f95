program bissec
implicit none

    REAL :: lower,upper,errorAprox,input,root
    INTEGER :: maxIterations,count
    CHARACTER(len = 32) ::arg
    CALL get_command_argument(1, arg)

    READ (arg, *) input
    IF (input < 0) THEN
        print *, "Valor inválido, precisa ser maior do que 0"
            stop 1
    END IF

    count = 0
    maxIterations = 10000
    errorAprox = 1E-6
    lower = 0
    upper = input
    root = (upper + lower) / 2


    DO WHILE (ABS (upper-root) >errorAprox .AND. count<maxIterations)
        IF ((root*2)>input) THEN
            upper = root
        
        ELSE
            lower = root

        END IF

        root = (upper+lower) / 2
        count = count + 1

    end do

    print *, root
END PROGRAM bissec