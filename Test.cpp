/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"

#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}
//My tests:

	testcase.setname("Throws")
	Guesser guess;
	Chooser choose;

	 .CHECK_THROWS()

	testcase.setname("My Calculate bull and pgia")
	  .CHECK_OUTPUT(calculateBullAndPgia("9106","1111"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9106","1000"), "1,1")      // 1 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9106","1022"), "0,1")      // 0 bull, 1 pgia

		.CHECK_OUTPUT(calculateBullAndPgia("3516","3516"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","3561"), "1,3")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","3156"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","1234"), "0,2")      // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","3214"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","2478"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","1365"), "0,4")      // 0 bull, 4 pgia

		.CHECK_OUTPUT(calculateBullAndPgia("8","1"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("8","8"), "1,0")      // 1 bull, 0 pgia
	
		.CHECK_OUTPUT(calculateBullAndPgia("82","12"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("82","21"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("82","14"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("82","82"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("82","28"), "0,2")      // 0 bull, 2 pgia

		.CHECK_OUTPUT(calculateBullAndPgia("371","371"), "3,0")      // 3 bull, 0 pgia
    .CHECK_OUTPUT(calculateBullAndPgia("371","137"), "0,3")      // 0 bull, 3 pgia
    .CHECK_OUTPUT(calculateBullAndPgia("371","317"), "1,2")      // 1 bull, 2 pgia
    .CHECK_OUTPUT(calculateBullAndPgia("371","242"), "0,0")      // 0 bull, 0 pgia



    for (int i=0; i<10; ++i)
		{
			for (int j=0; j<10; ++j)
			{
			if (i==j)
			.CHECK_OUTPUT(calculateBullAndPgia(to_string(i),to_string(j)), "1,0")      // 1 bull, 0 pgia
			else
			.CHECK_OUTPUT(calculateBullAndPgia(to_string(i),to_string(j)), "0,0")      // 0 bull, 0 pgia	
			}
		}

		for (int i=10; i<100; ++i)
		{
			for (int j=10; j<100; ++j)
			{
			if (i==j)
			.CHECK_OUTPUT(calculateBullAndPgia(to_string(i),to_string(j)), "2,0")      // 2 bull, 0 pgia
			else
			.CHECK_OUTPUT(calculateBullAndPgia(to_string(i),to_string(j)), "0,0")      // 0 bull, 0 pgia	
			}
		}

			for (int i=100; i<1000; ++i)
		{
			for (int j=100; j<1000; ++j)
			{
			if (i==j)
			.CHECK_OUTPUT(calculateBullAndPgia(to_string(i),to_string(j)), "3,0")      // 3 bull, 0 pgia
			else
			.CHECK_OUTPUT(calculateBullAndPgia(to_string(i),to_string(j)), "0,0")      // 0 bull, 0 pgia	
			}
		}

		for (int i=1000; i<10000; ++i)
		{
			for (int j=1000; j<10000; ++j)
			{
			if (i==j)
			.CHECK_OUTPUT(calculateBullAndPgia(to_string(i),to_string(j)), "4,0")      // 4 bull, 0 pgia
			else
			.CHECK_OUTPUT(calculateBullAndPgia(to_string(i),to_string(j)), "0,0")      // 0 bull, 0 pgia	
			}
		}
		;

		testcase.setname("My Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}