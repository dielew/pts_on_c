#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int week_day( int const year, int const month, int const day )
{
	int week_day;
	time_t *time_theday = (time_t*)malloc(sizeof(time_t));
	time(time_theday);
	struct tm* tm_theday = (struct tm*)malloc(sizeof(struct tm));
	tm_theday = localtime(time_theday);
	
	tm_theday->tm_year = year - 1900;
	tm_theday->tm_mon = month - 1;
	tm_theday->tm_mday = day;

	mktime(tm_theday);
	week_day = tm_theday->tm_wday;
	free(time_theday);
	free(tm_theday);
	
	return week_day;
}


int get_weekday( int const year, int const month, int const day )
{
	int ret_value = -1;
	if( year >= 1900 && year < 2038 && month >= 1 && month <= 12 ){ 
		if( month == 2 ){

			if( ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ){
				if( day >= 1 && day <= 29 ){
					ret_value = week_day(year, month, day);
				}
				else{
					ret_value = -1;
				}
			}

			else{
				if( day >= 1 && day <= 28 ){
					ret_value = week_day(year, month, day);
				}
				else{
					ret_value = -1;
				}
			}
		}
		else{
			if( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ){
				if( day >= 1 && day <= 31 ){
					ret_value = week_day(year, month, day);
				}
				else{
					ret_value = -1;
				}
			}
			else{
				if( day >= 1 && day <= 30 ){
					ret_value = week_day(year, month, day);
				}
				else{
					ret_value = -1;
				}
			}
		}
	}
	else{
		ret_value = -1;
	}

	return ret_value;
}


int main( int argc, char** argv )
{
	char week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int weekday_offset;
	int year;
	int month;
	int day;
	
	if( argc != 4 ){
		printf("Invalid number of arguments(!=4)\n");
		exit(1);
	}
	else{
		year = atoi(*++argv);
		month = atoi(*++argv);
		day = atoi(*++argv);

		weekday_offset = get_weekday(year, month, day);
		if( weekday_offset == -1){
			printf("Invalid command-line arguments! One or more of following causes:\n( out of range[1990-2038) / illegitimate date / nondigit ascii input )\n");
			exit(1);
		}
		else{
			printf("The day of week for the date as arguments %d-%d-%d is: %s\n", year, month, day, *(week + weekday_offset));
		}
	}

	return 0;
}
