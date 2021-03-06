
/*********************************************************************************************

                                cfglp : A CFG Language Processor
                                --------------------------------

           About:

           Implemented   by  Tanu  Kanvar (tanu@cse.iitb.ac.in) and Uday
           Khedker    (http://www.cse.iitb.ac.in/~uday)  for the courses
           cs302+cs306: Language  Processors (theory and lab)  at IIT
           Bombay.

           Release  date Jan  15, 2013.  Copyrights reserved  by Uday
           Khedker. This implemenation has been made available purely
           for academic purposes without any warranty of any kind.

           Documentation  (functionality,   manual, and  design)  and
           related tools are at http://www.cse.iitb.ac.in/~uday/cfglp


***********************************************************************************************/

#include<string>
#include<fstream>

using namespace std;

#include"local-environment.hh"
#include"error-display.hh"
#include"user-options.hh"

dtype Eval_Result::get_value()
{
	report_internal_error("Should not reach, Eval_Result : get_value");
}

void Eval_Result::set_value(dtype value)
{
	report_internal_error("Should not reach, Eval_Result : set_value");
}

bool Eval_Result::is_variable_defined()
{
	report_internal_error("Should not reach, Eval_Result : is_variable_defined");
}

void Eval_Result::set_variable_status(bool def)
{
	report_internal_error("Should not reach, Eval_Result : set_variable_status");
}

///////////////////////////////////////////////////////////////////////////////

void Eval_Result_Value::set_value(dtype value)
{
	
}

dtype Eval_Result_Value::get_value()
{
	dtype e;
	
	return e;
}

/*******************************************************************/
Eval_Result_Value_Int::Eval_Result_Value_Int()
{
	value.a = 0;
	value.b = 0.00;
	defined = false;
	result_type = int_result;
}

Eval_Result_Value_Int::~Eval_Result_Value_Int()
{ }

void Eval_Result_Value_Int::set_value(dtype number)
{
	value.a = number.a;
	value.b = number.b;
	defined = true;
}

dtype Eval_Result_Value_Int::get_value()
{
	return value;
}

void Eval_Result_Value_Int::set_variable_status(bool def)
{
	defined = def;
}

bool Eval_Result_Value_Int::is_variable_defined()
{
	return defined;
}

void Eval_Result_Value_Int::set_result_enum(Result_Enum res)
{
	result_type = res;
}

Result_Enum Eval_Result_Value_Int::get_result_enum()
{
	return result_type;
}
/***************************FLOAT >***************************************/


Eval_Result_Value_Float::Eval_Result_Value_Float()
{
	value.a = 0;
	value.b=0.00;
	defined = false;
	result_type = float_result;
}

Eval_Result_Value_Float::~Eval_Result_Value_Float()
{ }

void Eval_Result_Value_Float::set_value(dtype number)
{
	value.b = number.b;
	value.a = number.a;
	defined = true;
}

dtype Eval_Result_Value_Float::get_value()
{
	return value;
}

void Eval_Result_Value_Float::set_variable_status(bool def)
{
	defined = def;
}

bool Eval_Result_Value_Float::is_variable_defined()
{
	return defined;
}

void Eval_Result_Value_Float::set_result_enum(Result_Enum res)
{
	result_type = res;
}

Result_Enum Eval_Result_Value_Float::get_result_enum()
{
	return result_type;
}

/*******************< GO TO >*********************************************/

Eval_Result_Value_Goto::Eval_Result_Value_Goto()
{
	value.a = 0;
	value.b = 0;
	defined = false;
	result_type = goto_result;
}

Eval_Result_Value_Goto::~Eval_Result_Value_Goto()
{ }

void Eval_Result_Value_Goto::set_value(dtype number)
{
	value.a = number.a;
	value.b = number.a;
	defined = true;
}

dtype Eval_Result_Value_Goto::get_value()
{
	return value;
}

void Eval_Result_Value_Goto::set_variable_status(bool def)
{
	defined = def;
}

bool Eval_Result_Value_Goto::is_variable_defined()
{
	return defined;
}

void Eval_Result_Value_Goto::set_result_enum(Result_Enum res)
{
	result_type = res;
}

Result_Enum Eval_Result_Value_Goto::get_result_enum()
{
	return result_type;
}


///////////////////////////////////////////////////////////////////////////////////

Local_Environment::Local_Environment()
{}

Local_Environment::~Local_Environment()
{}

void Local_Environment::print(ostream & file_buffer)
{
	map<string, Eval_Result_Value *>::iterator i;
	for (i = variable_table.begin(); i != variable_table.end(); i++)
	{
		Eval_Result_Value * vi = variable_table[(*i).first];
		if (vi != NULL)
		{
			if (vi->is_variable_defined() == false)
				file_buffer << VAR_SPACE << (*i).first << " : undefined" << "\n";
		
			else{
				if  (vi->get_result_enum() == 0) {
					file_buffer << VAR_SPACE << (*i).first << " : " <<(vi->get_value()).a<<"\n";
				}
				else if (vi->get_result_enum() == 3) {
					file_buffer << VAR_SPACE << (*i).first << " : " <<(vi->get_value()).b<<"\n";
				}
			}
		}
	}
}

bool Local_Environment::is_variable_defined(string name)
{
	Eval_Result_Value * i = variable_table[name];
	if (i != NULL)
		return i->is_variable_defined();
	else
		return false;
}

Eval_Result_Value * Local_Environment::get_variable_value(string name)
{
	Eval_Result_Value * i = variable_table[name];
	return i;
}

void Local_Environment::put_variable_value(Eval_Result_Value & i, string name)
{
	variable_table[name] = &i;
}

bool Local_Environment::does_variable_exist(string name)
{
	if (variable_table[name] == NULL)
		return false;
	else
		return true;
}

map<string, Eval_Result_Value *>* Local_Environment::get_variable_table()
{
	return &variable_table;
}