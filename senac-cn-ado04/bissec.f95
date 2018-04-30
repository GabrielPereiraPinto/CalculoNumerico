program bissec
implicit none

    REAL :: lower,upper,med, input, error
    INTEGER :: iterations,i
    CHARACTER(len = 32) ::arg
    CALL get_command_argument(1, arg)

    READ (arg, *) input
    IF (input < 0) THEN
        print *, "Valor inválido, precisa ser maior do que 0"
            stop 1
    END IF
    
    iterations = 10000
    error = 0.0000001
    lower = 0
    upper = input

    DO i = 1, iterations
        med = (upper + lower) / 2.0

        if (med ** 2 ==input .OR. (upper - lower) / 2.0 < error) then

            print *, real(med)
            EXIT
        end if

        if (med **2 >input ) then
            upper = med 
        else if (med ** 2 < input) then
            lower = med 

        end if 
    end do

END PROGRAM bissec