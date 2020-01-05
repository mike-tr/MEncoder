# MEncoder
Trying to implement a modular encoding algorithm.

Me in my free time trying to implement the cool encoding algorithem, that we learned about at university.
the main idea, the porpuse, is

Given a message from A->B
we want to decode it while making sure the person B can extract the original, while also making sure,
that Peson C, cannot decode it, so only B has the password needed.

Principle,

Given q,p prime number we want, to have number e, we also have number n = q*p
such that gcd(e, phi(n)) = 1
now we need to calculate a number d such that e*d = 1 mod phi(n)
with all that, we now get that

given integer m, m < n we get that m^de = m mod n
we algo get that m^ee != m mod n, same for d

So now we get the following,
to decode a number m, lets call it d_m, e_m
we get that e_m = m^e mod n, d_m = m^d mod n

now to extract we simply need to pass, yet again m = e_m^d mod n,
and m = d_m^e mod n.

Given this functionality we get that,
we generate those (q,p) => e,n,d's to everyone (unqiue).

now every person has 2 sets of keys, e,d.
making sure d is protected and secret(or the other way around), and e,n is public.

now if A wanna send message to B, A->B , A takes his message and encode it using, e,n of person b
so he encodes his message m-> m_e = m^e mod n.

mow as person B has the key d, he can extract the data, while making it the only way to crack the data, is to calculate d. 
(with is very very hard, if n is a very large number)).
