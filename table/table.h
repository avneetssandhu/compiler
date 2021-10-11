#ifndef TABLE_H
#define TABLE_H

#include <time.h>
#include "../log/log.h"

struct Table_Time_Statistics {

};

struct Table_Time_Information {
	time_t time_time_created;
	time_t time_time_last_altered;
	time_t time_times_of_when_entries_added;
	time_t time_times_of_when_entries_removed;
	time_t time_times_of_when_permissions_changed;
	time_t time_all_times_names_have_changed;
	time_t time_all_times_table_rows_added;
	time_t time_all_times_table_rows_inserted;
	time_t time_all_times_table_columns_added;
	time_t time_all_times_table_columns_inserted;
	TABLE_TIME_STATISTICS table_time_statistics;	
};

struct Table_Miscellaneous_Information {
	char** all_pervious_names;
	int    num_of_times_realloced;
	void*  prev_locations_of_tables;
};

struct Data_Add_Information {
	void* data_all_data_added;
	int*  data_num_times_data_added;
	int*  data_indexes_of_data_added;
};

struct Data_Remove_Information {
	void* data_all_data_removed;
	int*  data_num_times_data_removed;
	int*  data_indexes_of_data_removed;
};

struct Data_Insert_Information {
	void* data_all_data_inserted;
	int*  data_num_times_data_inserted;
	int*  data_indexes_of_data_inserted;
};

struct Data_Alteration_Information {
	DATA_ADD_INFORMATION data_add_information;
	DATA_REMOVE_INFORMATION data_remove_information;
	DATA_INSERT_INFORMATION data_insert_information;

};

struct Table_Data_Information {
	int   data_unit_byte_size;
	int   data_units_units_in_table;
	int   data_units_units_max_in_table;
	int   data_units_bytes_in_table;
	int   data_units_bytes_max_in_table;
	DATA_ALTERATION_INFORMATION data_alteration_information;

};

struct Table {
	char* name;
	void* data;
	int   permissions;
	int*  all_previous_permissions;
	int   rows;
	int   columns;
	TABLE_DATA_INFORMATION table_data_information;
	TABLE_TIME_INFORMATION table_time_information;
	TABLE_MISCELLANEOUS_INFORMATION table_miscellaneous_information;
	LOG log;

};

typedef struct Table_Time_Statistics TABLE_TIME_STATISTICS;
typedef struct Table_Time_Information TABLE_TIME_INFORMATION;
typedef struct Table_Miscellaneous_Information TABLE_MISCELLANEOUS_INFORMATION;
typedef struct Data_Add_Information DATA_ADD_INFORMATION;
typedef struct Data_Remove_Information DATA_REMOVE_INFORMATION;
typedef struct Data_Insert_Information DATA_INSERT_INFORMATION;
typedef struct Data_Alteration_Information DATA_ALTERATION_INFORMATION;
typedef struct Table_Data_Information TABLE_DATA_INFORMATION;
typedef struct Table TABLE;

#endif /* TABLE_H */
