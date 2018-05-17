PROGRAM bhaskara

    IMPLICIT NONE

    INTEGER :: n
    CHARACTER(len= 32) :: arg, stringX1, stringX2, stringXi 
    DOUBLE PRECISION :: ABC(0:2), delta, x1, x2, xi
	
    DO n = 1, 3 
        CALL get_command_argument(n, arg)
        READ(arg,*) ABC(n-1) 
    END DO

    delta = getDelta(ABC(0), ABC(1), ABC(2))

    IF(delta>= 0.0) THEN 
			x1= (-ABC(1) + (delta ** 0.5)) / (2 * ABC(0)) 
			x2= (-ABC(1) - (delta ** 0.5)) / (2 * ABC(0))
			
			WRITE(stringX1, '(F0.16)') x1
			WRITE(stringX2, '(F0.16)') x2
			
			stringX1= writeX(stringX1)
			stringX2= writeX(stringX2)
			
			WRITE(*, '(A,A)') 'x1= ', stringX1
			WRITE(*, '(A,A)') 'x2= ', stringX2
			
		ELSE 
			delta= -delta 
			x1= -ABC(1) / (2 * ABC(0))
			xi= (delta ** 0.5) / (2 * ABC(0))
			
			WRITE(stringX1, '(F0.16)') x1 
			WRITE(stringXi, '(F0.16)') xi
			
			stringX1 = writeX(stringX1)
			stringXi = writeX(stringXi)
					
			WRITE(*, '(A,A,A,A,A)') 'x1 = ', trim(stringX1), ' + ', trim(stringXi), 'i'
			WRITE(*, '(A,A,A,A,A)') 'x2 = ', trim(stringX1), ' - ', trim(stringXi), 'i' 
    END IF
    
    CONTAINS
    
		FUNCTION getDelta(a, b, c) RESULT(result)
			DOUBLE PRECISION, intent(in) :: a, b, c
			DOUBLE PRECISION :: result
		
			result = (b ** 2) - (4 * a * c)
		END FUNCTION
		
		FUNCTION writeX(str) RESULT(result)
			CHARACTER(len = 32), intent(in) :: str
			CHARACTER(len = 32) :: result
			
			IF(str(1:1) == ".") THEN
				result = "0" // trim(str)
			ELSE IF(str(1:2) == "-.") THEN
				result = "-0" // trim(str(3:))
			ELSE
				result = str
			END IF 
		END FUNCTION

END PROGRAM