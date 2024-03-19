#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define MAXR    1000
#define STR     31
#define CMD     6
#define FILE_IN "log.txt"

typedef struct {
	int y;
	int m;
	int d;
} date_t;

typedef struct {
	int h;
	int m;
	int s;
} hour_t;

typedef struct {
	char id[STR];
	char source[STR];
	char destination[STR];
	char date_str[STR];
	char hour_dep_str[STR];
	char hour_arr_str[STR];
	int delay;
	date_t date;
	hour_t p, d;
} entry_t;

typedef struct table_ {
	int n_entries;
	entry_t log[MAXR];
} table_t;

typedef enum {r_date, r_source, r_end_of_line, r_delay, r_delay_tot, r_stop} command_e;

table_t readTable();

int dateSTR2INT(date_t date);
command_e readCommand(char commands[][STR]);
void printCommands(char commands[][STR]);
void wordMenu(table_t tab, command_e cmd);

int main(void) {

	char commands[][STR] = {"date", "source", "destination", "delay", "delay_tot", "stop"};
	int keep_on = 1;
	command_e cmd;
	table_t tab;

	tab = readTable();

	do {
		printCommands(commands);
		cmd = readCommand(commands);
		switch(cmd) {
			case r_date:
				wordMenu(tab, r_date);
				break;
			case r_source:
				wordMenu(tab, r_source);
				break;
			case r_end_of_line:
				wordMenu(tab, r_end_of_line);
				break;
			case r_delay:
				wordMenu(tab, r_delay);
				break;
			case r_delay_tot:
				wordMenu(tab, r_delay_tot);
				break;
			case r_stop:
				keep_on = 0;
				break;
			default:
				printCommands(commands);
		}
	} while(keep_on);
	return 0;
}


int compareDates1(date_t d1, date_t d2) {
	if (d1.y != d2.y)
		return (d1.y-d2.y);
	else if (d1.m != d2.m)
		return (d1.m-d2.m);
	else if (d1.d != d2.d)
		return (d1.d-d2.d);
	else return 0;
}

int compareDates2(date_t d1, date_t d2) {
	int date1, date2, res;

	date1= dateSTR2INT(d1);
	date2= dateSTR2INT(d2);
	if (date1 <= date2)
		res = -1;
	else
		res = 1;
	return res;
}

int dateSTR2INT(date_t date) {
	return 10000*date.y+100*date.m+date.d;
}

table_t readTable() {
	int i;
	table_t tab;
	FILE *in = fopen(FILE_IN, "r");
	if (in == NULL)
		exit(-1);

	fscanf(in, "%d", &tab.n_entries);
	for (i=0; i<tab.n_entries; i++) {
		fscanf(in, "%s %s %s %s %s %s %d\n", tab.log[i].id, tab.log[i].source, tab.log[i].destination, tab.log[i].date_str, tab.log[i].hour_dep_str, tab.log[i].hour_arr_str, &tab.log[i].delay);
		sscanf (tab.log[i].date_str,"%d/%d/%d", &tab.log[i].date.y,&tab.log[i].date.m,&tab.log[i].date.d);
		sscanf (tab.log[i].hour_dep_str,"%d:%d:%d", &tab.log[i].p.h,&tab.log[i].p.m,&tab.log[i].p.s);
		sscanf (tab.log[i].hour_arr_str,"%d:%d:%d", &tab.log[i].d.h,&tab.log[i].d.m,&tab.log[i].d.s);
	}

	return tab;
}

command_e readCommand(char commands[][STR]) {
	int i;
	char cmd[STR];
	printf("Command > ");
	scanf("%s", cmd);
	for (i=0; i<CMD; i++) {
		if (strcmp(cmd, commands[i]) == 0)
			return (command_e) i;
	}
	return -1;
}

void printCommands(char commands[][STR]) {
	int i;
	printf("\nAvailable commands:");
	for (i=0;i<CMD;i++)
		printf(" %s", commands[i]);
	printf("\n");
}

void printEntry(entry_t v) {
	printf("Line [%s] from %s to %s on %s (since %s to %s, with %d minut%s delay)\n", v.id, v.source, v.destination, v.date_str, v.hour_dep_str, v.hour_dep_str, v.delay, ((v.delay == 1) ? "e" : "es"));
}

void wordMenu(table_t tab, command_e cmd) {
	date_t d1, d2;
	char target[STR];
	int i, tot=0;
	if (cmd == r_date) {
		printf("Insert first date [yyyy/mm/dd]: ");
		scanf("%d/%d/%d", &d1.y,&d1.m,&d1.d);
		printf("Insert second date [yyyy/mm/dd]: ");
		scanf("%d/%d/%d", &d2.y,&d2.m,&d2.d);
	} else if (cmd == r_source) {
		printf("Insert source location: ");
		scanf("%s", target);
	} else if (cmd == r_end_of_line) {
		printf("Insert destination location: ");
		scanf("%s", target);
	} else if(cmd == r_delay) {
		printf("Insert first date [yyyy/mm/dd]: ");
		scanf("%d/%d/%d", &d1.y,&d1.m,&d1.d);
		printf("Insert second date [yyyy/mm/dd]: ");
		scanf("%d/%d/%d", &d2.y,&d2.m,&d2.d);
	} else if(cmd == r_delay_tot) {
		printf("Insert line id: ");
		scanf("%s", target);
	}

	for (i=0; i<tab.n_entries; i++) {
		switch(cmd) {
			case r_date:
				if (compareDates1(d1, tab.log[i].date) <= 0 && compareDates1(tab.log[i].date, d2) <= 0)
					printEntry(tab.log[i]);
				break;
			case r_source:
				if (!strcmp(tab.log[i].source, target))
					printEntry(tab.log[i]);
				break;
			case r_end_of_line:
				if (!strcmp(tab.log[i].destination, target))
					printEntry(tab.log[i]);
				break;
			case r_delay:
				if (compareDates1(d1, tab.log[i].date) <= 0 && compareDates1(tab.log[i].date, d2) <= 0 && tab.log[i].delay > 0)
					printEntry(tab.log[i]);
				break;
			case r_delay_tot:
				if (!strcmp(tab.log[i].id, target))
					tot += tab.log[i].delay;
				break;

			default: {
			}
		}
	}


	if (cmd == r_delay_tot)
		printf("Total delay %d\n", tot);
}
