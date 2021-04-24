#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<time.h>


struct flightData {
	int code;
	char airline[15];
	char departure[15];
	char destination[15];
	char deptime[6];
	char arrtime[6];
	int capacity;
	
};

struct passwordData {
	int pass;
};

struct bookingData {
	
	char name[15];
	int id;
	int seat;
	int bookingID;
	
};

void addbooking(FILE *cfptr2) {
	
	struct bookingData booking = {"",0,0,0};
	struct flightData flight = {0,"","","","","",0};
	
	srand(time(NULL));
	
	FILE *cfptr;
	
	int s_1 = rand() % 99;
	int s_2 = rand() % 99;
	int s_3 = rand() % 99;
	int s_4 = rand() % 99;
	int s_5 = rand() % 99;
	char depuser[15];
	char desuser[15];
	
	
	
	printf("The booked flights are listed.\n");
				
				if ( (cfptr = fopen("flight.dat","rb")) == NULL) {
					printf("File could not be opened.\n");
				}
				else {
					printf("%-12s%-9s%-18s%-20s%-15s%-13s%-9s\n","Flight Code","Airline","Departure Airport","Destination Airport","Departure Time","Arrival Time","Capacity");
					
					while( !feof(cfptr)) {
						
						fread(&flight, sizeof(struct flightData), 1, cfptr);
						
						if (flight.code != 0) {
							printf("%-12d%-9s%-18s%-20s%-15s%-13s%-10d\n", flight.code, flight.airline, flight.departure, flight.destination, flight.deptime, flight.arrtime, flight.capacity);
							break;
						}
				}
				fclose(cfptr);
				}
	printf("\nEnter your departure airport: ");
	scanf("%s", &depuser);
	printf("Enter your destination airport: ");
	scanf("%s", &desuser);
	
	if((cfptr2 = fopen("booking.dat","rb+")) == NULL) {
		printf("File could not be open.\n");
	}
	else {
		
		
		printf("Name: ");
		scanf("%s", &booking.name);
		printf("ID: ");
		scanf("%d", &booking.id);
		printf("Choose your seat. Empty seats: 26-%d-%d-%d-%d\n", s_1, s_2, s_3, s_4, s_5);
		printf("Your seat: ");
		scanf("%d", &booking.seat);
		
		booking.bookingID = booking.seat*10 + booking.id;
		fseek(cfptr, sizeof(struct bookingData), SEEK_END);
		fwrite(&booking, sizeof(struct bookingData), 1, cfptr);
		printf("Your booking ID is: %d\n", booking.bookingID);
		printf("New booking is added successfully!\n");
		
	}
	fclose(cfptr2);
	
};

void listedbookings(FILE *cfptr2) {
	
	struct bookingData booking = {"",0,0,0};
	struct flightData flight = {0,"","","","","",0};
	
	FILE *cfptr;
	
	
		printf("The bookings are listed.\n");			
				if ( (cfptr2 = fopen("booking.dat","rb")) == NULL) {
					printf("File could not be opened.\n");
				}
				else {
					printf("%-17s%-13s%-6s%-6s\n","Name","ID","Seat","Booking ID");
					
					while( !feof(cfptr2)) {
						
						fseek(cfptr2, sizeof(struct bookingData), SEEK_SET);
						fread(&booking, sizeof(struct bookingData), 1, cfptr2);
						
						if (booking.id != 0) {
							printf("%-17s%-13d%-6d%-6d\n", booking.name, booking.id, booking.seat, booking.bookingID);
							break;
							
						}
					}
					fclose(cfptr2);
					
				if ( (cfptr = fopen("flight.dat","rb")) == NULL) {
					printf("File could not be opened.\n");
				}
				else {
					printf("%-12s%-9s%-18s%-20s%-15s%-13s%-9s\n","Flight Code","Airline","Departure Airport","Destination Airport","Departure Time","Arrival Time","Capacity");
					
					while( !feof(cfptr)) {
						
						fread(&flight, sizeof(struct flightData), 1, cfptr);
						
						if (flight.code != 0) {
							
							printf("%-12d%-9s%-18s%-20s%-15s%-13s%-10d\n", flight.code, flight.airline, flight.departure, flight.destination, flight.deptime, flight.arrtime, flight.capacity);
							break;
							
						}
						
				}
				fclose(cfptr);
				
					
}


}

};

void cancelbooking(FILE *cfptr2) {
	struct bookingData booking;
	struct bookingData blankBooking = {"",0,0,0};
	
	cfptr2 = fopen("booking.dat","rb");
	printf("Enter your booking ID to cancel your booking: ");
	scanf("%d", &booking.bookingID);
	
	fseek(cfptr2, sizeof(struct bookingData), SEEK_SET);
	fread(&booking, sizeof(struct bookingData), 1, cfptr2);
	
	if ( booking.bookingID == 0) {
		printf("This booking does not exist.\n");
	}
	else {
		fseek(cfptr2, sizeof(struct bookingData), SEEK_SET);
		fwrite(&blankBooking,sizeof(struct bookingData), 1, cfptr2);
		printf("The booking is canceled successfully!\n");
		
		
	}
	fclose(cfptr2);
	
};


void changepassword(FILE *cfptr3) {
	
	struct passwordData password = {0};
	
	
	if ((cfptr3 = fopen("password.dat","rb+")) == NULL) {
		printf("File could not be open.\n");
	}
	else {
		printf("Enter the new password: ");
		scanf("%d", &password.pass);
		printf("Enter the new password: ");
		scanf("%d", &password.pass);
		printf("New password is %d.\n", password.pass);
		
		while (password.pass != 0) {
			fscanf(stdin,"%d",password.pass);
			fseek(cfptr3,sizeof(struct passwordData), SEEK_SET);
			fwrite(&password,sizeof(struct passwordData), 1, cfptr3);
		}
		
		fclose(cfptr3);
			
	}
	
	
};

void addflight(FILE *cfptr) {
	struct flightData flight = {0,"","","","","",0};

	
	if((cfptr= fopen("flight.dat","rb+")) == NULL) {
		printf("File could not be open.\n");
	}
	else {
		printf("Enter required information.\n");
		
		printf("Flight code: ");
		scanf("%d", &flight.code);
		printf("Airline: ");
		scanf("%s", &flight.airline);
		printf("Departure Airport: ");
		scanf("%s", &flight.departure);
		printf("Destination Airport: ");
		scanf("%s", &flight.destination);
		printf("Departure Time: ");
		scanf("%s", &flight.deptime);
		printf("Arrival Time: ");
		scanf("%s", &flight.arrtime);
		printf("Capacity: ");
		scanf("%d", &flight.capacity);
		
		fwrite(&flight, sizeof(struct flightData), 1, cfptr);
		printf("New flight is added successfully!\n");
		
	}
	
	
};

void editflight(FILE *cfptr) {
	
	struct flightData flight = {0,"","","","","",0};
	
	int upd_code;
	char upd_airline[15];
	char upd_departure[15];
	char upd_destination[15];
	char upd_deptime[6];
	char upd_arrtime[6];
	int upd_capacity;
	
	printf("Enter the code of the flight: ");
	scanf("%d", &upd_code);
	
	cfptr = fopen("flight.dat","rb+");
	
	fseek(cfptr,(upd_code - 1)*sizeof(struct flightData), SEEK_SET);
	fread(&flight,sizeof(struct flightData), 1, cfptr);
	
	if ( (cfptr = fopen("flight.dat","rb")) == NULL) {
					printf("File could not be opened.\n");
				}
				else {
					printf("%-12s%-9s%-18s%-20s%-15s%-13s%-9s\n","Flight Code","Airline","Departure Airport","Destination Airport","Departure Time","Arrival Time","Capacity");
					
					while( !feof(cfptr)) {
						
						fread(&flight, sizeof(struct flightData), 1, cfptr);
						
						if (flight.code != 0) {
							
							printf("%-12d%-9s%-18s%-20s%-15s%-13s%-10d\n", flight.code, flight.airline, flight.departure, flight.destination, flight.deptime, flight.arrtime, flight.capacity);
							
						}
						
				}
		
	printf("Enter the new information about the flight, if there are changes.\n");
		
	printf("Flight Code: ");
	scanf("%d", &upd_code);
	flight.code = upd_code;
		
	printf("Airlines: ");
	scanf("%s", &upd_airline);
	*flight.airline =  *upd_airline;
		
	printf("Departure Airport: ");
	scanf("%s", &upd_departure);
	*flight.departure = *upd_departure;
		
	printf("Destination Airport: ");
	scanf("%s", &upd_destination);
	*flight.destination = *upd_destination;
		
	printf("Departure Time: ");
	scanf("%s", &upd_deptime);
	*flight.deptime = *upd_deptime;
		
	printf("Arrival Time: ");
	scanf("%s", &upd_arrtime);
	*flight.arrtime = *upd_arrtime;
		
	printf("Capacity: ");
	scanf("%d", &upd_capacity);
	flight.capacity = upd_capacity;
	
	fseek(cfptr,(upd_code - 1)*sizeof(struct flightData), SEEK_SET);
	fwrite(&flight, sizeof(struct flightData), 1, cfptr);
	fclose(cfptr);
	printf("New information is saved.\n");

	}
};

void deleteflight(FILE *cfptr) {
	struct flightData flight;
	struct flightData blankFlight = {0,"","","","","",0};
	
	int delcode;
	
	printf("Enter the flight code of the flight you want to delete: ");
	scanf("%d", &flight.code);
	
	fseek(cfptr, sizeof(struct flightData), SEEK_SET);
	fread(&flight, sizeof(struct flightData), 1, cfptr);
	
	if (flight.code != 0) {
		printf("This flight does not exist.\n");
	}
	else {
		fseek(cfptr, sizeof(struct flightData), SEEK_SET);
		fwrite(&blankFlight,sizeof(struct flightData), 1, cfptr);
		printf("The flight is deleted successfully!\n");
	}
	
	
};

void returntomenu( ) {
	
	start:
		goto start;
	
}






int main( ) {
	
	Menu:
	
	struct flightData flight = {0,"","","","","",0};
	
	FILE *cfptr, *cfptr2, *cfptr3;
	
	int a, pass, choice;

	printf("\t\t*** WELCOME TO AIRLINES RESERVATION SYSTEM ***\n\n");
	
	printf("Press 1 for ADMIN menu and 2 for PASSENGER menu:");
	
	scanf("%d",&a);

	
	
	while( a == 1) {
		
		struct flightData flight = {0,"","","","","",0};
		struct passwordData password = {0};
		
		printf("Enter the password: ");
		scanf("%d", &pass);
		
		cfptr3 = fopen("password.dat","rb");
		fseek(cfptr3,(pass-1)*sizeof(struct passwordData), SEEK_SET);
		fread(&password, sizeof(struct passwordData), 1, cfptr3);
				
		if ( pass == 1257 || password.pass == pass) {
			
			printf("Password is valid. Welcome!\n");
			
			int b;
			
			printf("1==>ADD/EDIT/DELETE FLIGHT\n2==>LIST AVAILABLE FLIGHTS\n3==>LIST CURRENT BOOKINGS\n4==>CHANGE ADMIN PASSWORD\n5==>RETURN TO MAIN MENU\n");
			scanf("%d", &b);
			
			while (b == 1) {
				
				if ( (cfptr=fopen("flight.dat","rb+")) == NULL) {
					printf("File could not be opened.\n");
				}
				else {
					printf("1==>ADD FLIGHT\n2==>EDIT FLIGHT\n3==>DELETE FLIGHT\n");
					scanf("%d", &choice);
					
					switch(choice) {
						case 1:
							addflight(cfptr);
							break;
						case 2:
							editflight(cfptr);
							break;
						case 3:
							deleteflight(cfptr);
							break;
					}
					fclose(cfptr);
				}
				return 0;
			}
			while (b == 2) {
				struct flightData flight = {0,"","","","","",0};
								
				printf("The booked flights are listed.\n");
				
				if ( (cfptr=fopen("flight.dat","rb")) == NULL) {
					printf("File could not be opened.\n");
				}
				else {
					printf("%-12s%-9s%-18s%-20s%-15s%-13s%-9s\n","Flight Code","Airline","Departure Airport","Destination Airport","Departure Time","Arrival Time","Capacity");
					
					while( !feof(cfptr)) {
						
						fread(&flight, sizeof(struct flightData), 1, cfptr);
						
						if (flight.code != 0) {
							printf("%-12d%-9s%-18s%-20s%-15s%-13s%-10d\n", flight.code, flight.airline, flight.departure, flight.destination, flight.deptime, flight.arrtime, flight.capacity);
							break;
							
						}
					}
					fclose(cfptr);
				}
				return 0;
					
			}
			while ( b == 3) {
				
				listedbookings(cfptr2);
				break;
				
			}
			
			while( b == 4) {
				
				struct passwordData password = {0};
				
				int currpass;
				
				printf("Please enter the current password: ");
				scanf("%d", &currpass);
				
				cfptr3 = fopen("password.dat","rb");
				fseek(cfptr3,sizeof(struct passwordData), SEEK_SET);
				fread(&password, sizeof(struct passwordData), 1, cfptr3);
				
				if (currpass == 1257) {
					
					printf("Password is correct!\n");
					changepassword(cfptr3);
					return 0;
				}
				else {
					printf("You entered a wrong password!\n");
				}
				return 0;
				}
				
			while( b==5 ) {
				system("cls");
				goto Menu;
			} 
			}
			else {
				printf("You entered a wrong password!\n\n");
				goto Menu;
				return 0;
			}
			
			
			}				
	
	
	while (a == 2) {
		
		int choice2;
		int rescode;
		char name[15];
		int id;
		char depuser[15];
		char desuser[15];
		int seat;
		int bookingID;
		
		struct flightData flight = {0,"","","","","",0};
		struct bookingData booking= {"",0,0,0};
		
		printf("Welcome to user menu.\n1==BOOK A FLIGHT\n2==>CANCEL A BOOKING\n3==>LIST BOOKED FLIGHTS\n4==>RETURN TO MAIN MENU\n");
		scanf("%d",&choice2);
		
		switch(choice2) {
			case 1:
				
				addbooking(cfptr);
				break;
				
			case 2:
				
				cancelbooking(cfptr);
				break;
				
			case 3:
				
				
				listedbookings(cfptr);
				break;
				
			case 4:
				system("cls");
				goto Menu;
				break;
				
			}
			return 0;
			}
			
			
		}
	
	
	
			
				
				
			
				
								
				
				
				
	


		
		
	
		



	

