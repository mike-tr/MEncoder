# MEncoder
Trying to implement a modular encoding algorithm.

Me in my free time trying to implement the cool encoding algorithem, that we learned about at university.
the main idea, is as follows.

Given a message we want to send from A->B
we want to ecode it while making sure the person B can extract the original, while also making sure,
that Peson C, cannot decode it, so only B has the password needed.

More in depth?

now every person has 2 sets of keys, e,d as well as public integer n (visible for everyone).
making sure d is protected and secret, and e public. (or the other way around)

that are having the following proprties, given integer m < n
m^ed = m mod n, while also making sure m^e = m_e mod n, m^d = m_d  mod n.
while m_e,m_d are not equal to m (for some number m, a.k.a if m is 0,1 it doesnt follows).

now if A wanna send message to B, A->B , A takes his message and encode it using the public key e of person B, as well as his base n.
so he encodes his message m-> m_e = m^e mod n.

mow as person B has the key d, he can extract the data, while making it the only way to crack the data, is to calculate d. 
(with is very very hard, if n is a very large number)).


How it works?

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


