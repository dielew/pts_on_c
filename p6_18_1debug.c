#include <stdio.h>
#define V_MAX 1000


void *find_char( char const *source, char const *chars ){
	void *r_val = NULL;
	char const *c_orig = chars;
	if( source == NULL || chars == NULL || *source == '\0' || *chars == '\0' )
		r_val = NULL;
	else{
		//printf("source = [%s]\n",source);
		//printf("chars = [%s]\n",chars);
		while( *source++ != '\0' ){
		    printf("parse rouce [%c]\n",*source);
			while( *chars++ != '\0' ){
				printf("parse char [%c]\n",*chars);
				if( *source == *chars ){
					r_val = source;
					printf("find char [%c]\n",(char *)r_val);
					break;
					
				}
			}
			printf("now rval is null[%d]\n",r_val == NULL);
			if( NULL != r_val )
				break;
			else
				chars = c_orig;
		}
	}
	return r_val;
}


int main(int argc,char **argv){
	if(argc < 3){
		fprintf(stderr,"Usage %s source char\n",argv[0]);
		return 0;
	}
	char const source[V_MAX];
	char const chars[V_MAX];
	char const *res;

	//printf("Please input the source string:");
	//scanf("%s", source);
	snprintf(source,V_MAX,"%s",argv[1]);
	snprintf(chars,V_MAX,"%s",argv[2]);
	//printf("Please input the target string:");
	//scanf("%s", chars);
	res = find_char(source, chars);
	if( NULL == res )
		printf("Source string: %s\nTarget string: %s\nChar pointed: matchable char unfound!\n", source, chars);
	else
		printf("Source string: %s\nTarget string: %s\nChar pointed: %c\n", source, chars, *res);
	return 0;
}
