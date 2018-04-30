program bissec
implicit none

    REAL ::     lower,  upper,  errorAprox, input,  root
    INTEGER :: maxIterations,   count
    CHARACTER(len = 32) ::arg
    call get_command_artgument(1,arg)

    read (arg,*) input
    if (input <0)
        print *, "Valor inválido, precisa ser maior do que 0"
            stop 1
    end if

    count = 0
    maxIterations = 10000
    errorAprox = 1E-6
    lower = 0
    upper = input
    root = (upper + lower) / 2


    do while (ABS (uper-root) >errorAprox .AND. count<maxIterations)
        if ((root*2)>input) then
            upper = root
        
        else
            lower = root

        end if

        root = (upper+lower) / 2
        count - count + 1

    end do

    print *, root
end program bissec