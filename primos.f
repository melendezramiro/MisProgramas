
integer, parameter              :: last_number = 100000000

integer, dimension(last_number) :: numbers

integer                         :: i, number_of_primes, ac

!  Initialize numbers array to 0, 2, 3, ..., last_number--
!  Zero instead of 1 because 1 is a special case.
numbers = (/ 0, (ac, ac = 2, last_number) /)

do i = 2, last_number
  if (numbers(i) /= 0) then              ! if this number is prime
    numbers(2*i : last_number : i) = 0   ! eliminate all multiples
  endif
enddo

!  Count the primes.
number_of_primes = count (numbers /= 0)

!  Gather them into the front of the array.
numbers(1:number_of_primes) = pack(numbers, numbers /= 0)

!  Print them
print *, "There are ", number_of_primes, &
         " prime numbers less than", last_number
!print "(5i7)", numbers(1:number_of_primes)
