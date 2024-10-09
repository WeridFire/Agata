#pragma once
enum class Directions
{

	/*
	  northwest    north   northeast
	  noWe         nort         noEa
			  +7    +8    +9
				  \  |  /
	  west    -1 <-  0 -> +1    east
				  /  |  \
			  -9    -8    -7
	  soWe         sout         soEa
	  southwest    south   southeast
	*/


	noWe = 7,
	nort = 8,
	noEa = 9,

	west = -1,
	east = 1,

	soWe = -9,
	sout = -8,
	soEa = -7
};

