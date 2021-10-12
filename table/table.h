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


#define Data_XXX_Information_Struct_Gen(name_in_struct, name_in_variables )	struct Data_ ##name_in_struct ##_Information {							     \
		void* data_all_data_ ##name_in_variables;			\
		int*  data_num_times_ ##name_in_variables;			\
		int*  data_indexes_of_data_ ##name_in_variables; 		\
	}

#define Data_XXX_Information_Struct_Typedef(name_in_struct, name_in_typedef) typedef struct Data_ ##name_in_struct ##_Information DATA_ ##name_in_typedef ##_INFORMATION

Data_XXX_Information_Struct_Gen(Add, added);
Data_XXX_Information_Struct_Gen(Remove, removed);
Data_XXX_Information_Struct_Gen(Insert, inserted);
Data_XXX_Information_Struct_Typedef(Add, ADD);
Data_XXX_Information_Struct_Typedef(Remove, REMOVE);
Data_XXX_Information_Struct_Typedef(Insert, INSERT);


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
typedef struct Data_Alteration_Information DATA_ALTERATION_INFORMATION;
typedef struct Table_Data_Information TABLE_DATA_INFORMATION;
typedef struct Table TABLE;

#endif /* TABLE_H */
