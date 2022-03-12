**Creating different mendelbulb shape**

formula for this:

 There are a few subtle variations, which mostly end up producing the same kind of incredible detail. Listed below is one version. Similar to the original 2D Mandelbrot, the 3D formula is defined by:

z -> z^n + c

...but where 'z' and 'c' are hypercomplex ('triplex') numbers, representing Cartesian x, y, and z coordinates. The exponentiation term can be defined by:

{x,y,z}^n = r^n { sin(theta*n) * cos(phi*n) , sin(theta*n) * sin(phi*n) , cos(theta*n) }

...where:

r = sqrt(x^2 + y^2 + z^2)

theta = atan2( sqrt(x^2+y^2), z )

phi = atan2(y,x)

And the addition term in z -> z^n + c is similar to standard complex addition, and is simply defined by:

{x,y,z}+{a,b,c} = {x+a, y+b, z+c}

The rest of the algorithm is similar to the 2D Mandelbrot!

Here is some pseudo code of the above:

r = sqrt(x*x + y*y + z*z )

theta = atan2(sqrt(x*x + y*y) , z)

phi = atan2(y,x)

newx = r^n * sin(theta*n) * cos(phi*n)

newy = r^n * sin(theta*n) * sin(phi*n)

newz = r^n * cos(theta*n)

...where n is the order of the 3D Mandelbulb. Use n=8 to find the exact object in this article.

The formulae above is the higher power analogue to the first green object shown on the first page here, but also see the formulae on Paul Nylander's page, which corresponds to the second green object shown instead. Both produce amazing (and similar) objects when put to the higher powers. Also see this summary of formulas.

There are also techniques to improve rendering speed as found by FractalForum.com members:
Distance estimation provided by David Makin.
Powers -2 to 4 and powers 5 to 8, without the trig, to increase speed, by Paul Nylander. Also see Karl's earlier version for power 2 to check for "divide by zero" errors for the y values. One may need to use that technique for the higher powers too.
.
.
.


