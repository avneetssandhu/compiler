#ifndef TABLE_H
#define TABLE_H

#include <time.h>
#include "../embedded_data/embedded_data.h"
#include "../log/log.h"
#include "../permissions/permissions.h"

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



#define Table_Data_XXX_Information_Struct_Gen(name_in_struct, name_in_variables )	struct Table_Data_ ##name_in_struct ##_Information {							     \
		void* table_data_all_data_ ##name_in_variables;			\
		int*  table_data_num_times_ ##name_in_variables;			\
		int*  table_data_indexes_of_data_ ##name_in_variables; 		\
	}

#define Table_Data_XXX_Information_Struct_Typedef(name_in_struct, name_in_typedef) typedef struct Table_Data_ ##name_in_struct ##_Information DATA_ ##name_in_typedef ##_INFORMATION

Table_Data_XXX_Information_Struct_Gen(Add, added);
Table_Data_XXX_Information_Struct_Gen(Remove, removed);
Table_Data_XXX_Information_Struct_Gen(Insert, inserted);
Table_Data_XXX_Information_Struct_Typedef(Add, ADD);
Table_Data_XXX_Information_Struct_Typedef(Remove, REMOVE);
Table_Data_XXX_Information_Struct_Typedef(Insert, INSERT);

struct Table_Data_Alteration_Information {
	TABLE_DATA_ADD_INFORMATION table_data_add_information;
	TABLE_DATA_REMOVE_INFORMATION table_data_remove_information;
	TABLE_DATA_INSERT_INFORMATION table_data_insert_information;
};


typedef struct Table_Data_Alteration_Information TABLE_DATA_ALTERATION_INFORMATION;

struct Table_Data_Information {
	int   data_units_num_in_table;
	int   data_units_max_in_table;
	TABLE_DATA_ALTERATION_INFORMATION table_data_alteration_information;
};

typedef struct Table_Time_Statistics TABLE_TIME_STATISTICS;
typedef struct Table_Time_Information TABLE_TIME_INFORMATION;
typedef struct Table_Miscellaneous_Information TABLE_MISCELLANEOUS_INFORMATION;
typedef struct Table_Data_Information TABLE_DATA_INFORMATION;

struct Table {
	EMBEDDED_DATA embedded_data;
	int   rows;
	int   columns;
	TABLE_DATA_INFORMATION table_data_information;
	TABLE_TIME_INFORMATION table_time_information;
	TABLE_MISCELLANEOUS_INFORMATION table_miscellaneous_information;
	LOG log;
};

typedef struct Table TABLE;

#endif /* TABLE_H */
