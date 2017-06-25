const int kMaxNumberOfPages = 9;
const int kMinNumberOfPages = 0;
int       iCurrentMotor = 1;

float
logDrive (int iInput, float iMultiply) {
	return (pow(abs(iInput), iMultiply)) * sgn(iInput);
}

task 
main( ) {
	while( true ) {
		if( vexRT[Btn5U] == 1 ) {
			iCurrentMotor = iCurrentMotor == kMinNumberOfPages ? kMaxNumberOfPages : iCurrentMotor - 1;
			while(vexRT[Btn5U]){}
		}
		if( vexRT[Btn6U] == 1 ) {
			iCurrentMotor = iCurrentMotor == kMaxNumberOfPages ? kMinNumberOfPages : iCurrentMotor + 1;
			while(vexRT[Btn6U]){}
		}
		
		motor[ iCurrentMotor ] = logDrive(vexRT[Ch2], 1.1);
	}
}
