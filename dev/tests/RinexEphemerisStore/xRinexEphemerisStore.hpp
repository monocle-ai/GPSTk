#pragma ident "$Id$"
// file: xRinexEphemerisStore.hpp

#ifndef XRINEXEPHEMERISSTORE_HPP
#define XRINEXEPHEMERISSTORE_HPP

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "RinexEphemerisStore.hpp"
#include "SatID.hpp"
#include <fstream>


using namespace std;

 
class xRinexEphemerisStore: public CPPUNIT_NS :: TestFixture
{
	//Test Fixture information, e.g. what tests will be run
	CPPUNIT_TEST_SUITE (xRinexEphemerisStore);
	CPPUNIT_TEST (RESTest);
	CPPUNIT_TEST (BCESfindEphTest);
	CPPUNIT_TEST (BCESgetXvtTest);
	CPPUNIT_TEST (BCESgetXvt2Test);
	CPPUNIT_TEST (BCESgetSatHealthTest);
	CPPUNIT_TEST (BCESdumpTest);
	CPPUNIT_TEST (BCESaddEphemerisTest);
	CPPUNIT_TEST (BCESeditTest);
	CPPUNIT_TEST (BCESwiperTest);
	CPPUNIT_TEST (BCESclearTest);
	CPPUNIT_TEST (BCESfindUserTest);
	CPPUNIT_TEST (BCESfindNearTest);
	CPPUNIT_TEST (BCESaddToListTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void); //Sets up test enviornment
		
	protected:
		
		void RESTest (void); 
		void BCESfindEphTest (void);
		void BCESgetXvtTest (void);
		void BCESgetXvt2Test (void);
		void BCESgetSatHealthTest (void);
		void BCESdumpTest (void);
		void BCESaddEphemerisTest (void);
		void BCESeditTest (void);
		void BCESwiperTest (void);
		void BCESclearTest (void);
		void BCESfindUserTest (void);
		void BCESfindNearTest (void);
		void BCESaddToListTest (void);
		bool fileEqualTest (char[], char[]);

	private:		

};	
#endif
