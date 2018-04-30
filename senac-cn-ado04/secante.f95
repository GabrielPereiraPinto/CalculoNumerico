program  secante
implicit none

    integer iterations, i
    real  input, p0, p1, pn, error
    CHARACTER(len = 32) ::arg
    CALL get_command_argument(1, arg)

    READ (arg, *) input
    IF (input < 0) THEN
        print *, "Valor inválido, precisa ser maior do que 0"
            stop 1
    END IF

    p0 = input
    pn = input -1.0

    do i=1, iterations
        p1 = (p0 * pn + input) / (p0 +pn)

        if (abs(p1-pn) < error .or. p1 ** 2 == input) then
            print *, real(p1)
            EXIT
        end if 
        
        p0 = p
        pn= p1
end program  secante
    