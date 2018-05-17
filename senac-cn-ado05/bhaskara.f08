program bhaskara

    implicit none

    integer :: n
    character(len= 32) :: arg, stringx1, stringx2, stringxi
    double precision :: abc(0:2), delta, x1, x2, xi
    
    do n = 1, 3
        call get_command_argument(n, arg)
        read(arg,*) abc(n-1)
    end do

    delta = getdelta(abc(0), abc(1), abc(2))

    if(delta>= 0.0) then
            x1= (-abc(1) + (delta ** 0.5)) / (2 * abc(0))
            x2= (-abc(1) - (delta ** 0.5)) / (2 * abc(0))
            
            write(stringx1, '(f0.16)') x1
            write(stringx2, '(f0.16)') x2
            
            stringx1= writex(stringx1)
            stringx2= writex(stringx2)
            
            write(*, '(a,a)') 'x1= ', stringx1
            write(*, '(a,a)') 'x2= ', stringx2
            
        else
            delta= -delta
            x1= -abc(1) / (2 * abc(0))
            xi= (delta ** 0.5) / (2 * abc(0))
            
            write(stringx1, '(f0.16)') x1
            write(stringxi, '(f0.16)') xi
            
            stringx1 = writex(stringx1)
            stringxi = writex(stringxi)
                    
            write(*, '(a,a,a,a,a)') 'x1 = ', trim(stringx1), ' + ', trim(stringxi), '  i'
            write(*, '(a,a,a,a,a)') 'x2 = ', trim(stringx1), ' - ', trim(stringxi), ' i'
    end if
    
    contains
    
        function getdelta(a, b, c) result(result)
            double precision, intent(in) :: a, b, c
            double precision :: result
        
            result = (b ** 2) - (4 * a * c)
        end function
        
        function writex(str) result(result)
            character(len = 32), intent(in) :: str
            character(len = 32) :: result
            
            if(str(1:1) == ".") then
                result = "0" // trim(str)
            else if(str(1:2) == "-.") then
                result = "-0" // trim(str(3:))
            else
                result = str
            end if
        end function

end program
