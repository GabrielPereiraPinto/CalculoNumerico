program newton
implicit none

    real :: input, p0, p, error
    integer :: iterations, i
    CHARACTER(len = 32) ::arg
    CALL get_command_argument(1, arg)

    READ (arg, *) input
    IF (input < 0) THEN
        print *, "Valor inválido, precisa ser maior do que 0"
            stop 1
    END IF

    iterations = 10000
    error = 0.0000001
    p0=input

    do i=1, iterations
        p = (p0 + (input/p0)) /2
        if (abs(p-p0) <error .or. p**2==input) then
            print *, real(p)
            EXIT
        end if

        p0=p
    end do

end program newton