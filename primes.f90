!compilar con: gfortran primes.f90 -o primes -fno-range-check

program Sieve_Of_Eratosthenes

integer, parameter              :: last_number = 10000000000
integer, dimension(last_number) :: numbers
integer                         :: i, number_of_primes, ac

!  Initialize numbers array to 0, 2, 3, ..., last_number--
!  Zero instead of 1 because 1 is a special case.
numbers = (/ 0, (ac, ac = 2, last_number) /)

do i = 2, INT(sqrt(REAL(last_number)))	!disminuye la cantidad de calculos
  if (numbers(i) /= 0) then              ! if this number is prime
    numbers(2*i : last_number : i) = 0   ! eliminate all multiples
  endif
enddo

!  Count the primes.
number_of_primes = count (numbers /= 0)

!  Gather them into the front of the array.
numbers(1:number_of_primes) = pack(numbers, numbers /= 0)

!  Print them
print "(7i12)", numbers(1:number_of_primes)
print *, "There are ", number_of_primes, &
         " prime numbers less than", last_number

end program Sieve_Of_Eratosthenes
