program bhaskara
implicit none

    integer :: n
    character(len=32) :: arg, stringX1, stringX2, stringXi
    double precision :: inputs(0:2), delta, x1, x2, xi, xreal

    do i =1,3
        call GET_COMMAND_ARGUMENT(i,arg)
        read (arg, *) inputs (i-1)
    end do 

    delta = getDelta(inputs(0), inouts(1), inputs(2))

    if (delta >=0.0) then 
        x1= (-inputs(1) + (delta ** 0.5)) / (2* inputs (0))
        x2= (-inputs(1) - (delta ** 0.5)) / (2* inputs (0))

        write(stringX1, '(F0.16)') x1
        write(stringX2, '(F0.16)') x2

        stringX1= escreveX(stringX1)
        stringX2= escreveX(stringX2)

        write(*, '(A,A)') 'x1 =', stringX1
        write(*, '(A,A)') 'x2 =', stringX2
    
    else 
        delta = -delta
        xreal= -inputs(1) / (2*inputs(0))
        xi= (delta **0.5) / (2*inputs(0))

        write(stringX1, '(F0.16)') xreal
        write(stringX2, '(F0.16)') xi 

        stringX1= escreveX(stringX1)
        stringXi= escreveX(stringXi)

        write(*, '(A,A,A,A,A)') 'X1 =', trim(stringX1), ' + ', trim (stringXi), 'i'
        write(*, '(A,A,A,A,A)') 'X1 =', trim(stringX1), ' - ', trim (stringXi), 'i'

    end if 

    CONTAINS
        
    function getDelta(a,b,c) result (output)
        double precision, intent(in) :: a,b,c 
        double precision :: output

        output = (b**2) - (4*a*c)
    end function

     function escreveX(str) result(output)
        character(len=32), intent(in) :: str 
        character(len=32) :: output 

        if(str(1:1) == ".") then 
            output = "0" // trim(str)
        else if (str(1:2) == "-.") then 
            output = "-0" // trim(str(3:)) 
        else 
            output = str 
        end if 
    end function 


end program bhaskara
