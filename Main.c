const int kMaxNumberOfPages = 9;
const int kMinNumberOfPages = 0;
int       iCurrentMotor = 1;

void
allMotorsOff( ) {
	for( int i = 0; i < 10; i++ )
		motor[ i ] = 0;
}

void
clearAllLCDLines( ) {
	clearLCDLine( 0 );
	clearLCDLine( 1 );
}

task
main( ) {
	iCurrentMotor = 0;
	while( true ) {
		if( nLCDButtons == 1 ) {
			iCurrentMotor = iCurrentMotor == kMinNumberOfPages ? kMaxNumberOfPages : iCurrentMotor - 1;
			while(nLCDButtons!=0){}
			allMotorsOff( );
		}
		if( nLCDButtons == 4 ) {
			iCurrentMotor = iCurrentMotor == kMaxNumberOfPages ? kMinNumberOfPages : iCurrentMotor + 1;
			while(nLCDButtons!=0){}
			allMotorsOff( );
		}

		motor[ iCurrentMotor ] = nLCDButtons == 2 ? 127 : 0;
		
		displayLCDCenteredString( 0, "Port #" );
		displayLCDNumber( 0, 11, iCurrentMotor+1 );
		displayLCDString( 1, 0, "<");
		displayLCDString( 1, 15, ">");
		string strCurrentMotorState = abs(motor[iCurrentMotor])>=0 ? "ON" : "OFF";
		displayLCDString( 1, 2, strCurrentMotorState);
		delay( 50 );
		clearAllLCDLines( );
	}
}
