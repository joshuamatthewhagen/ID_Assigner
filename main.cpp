#include <iostream>
#include <vector>
#include <map>

class object
{
public:
	std::string say(std::string string);

private:
	int get_id(std::string string);
	static int id;

	// map to map a string with an id
	std::map<std::string, int> object_map;

	// vector to check if string exists
	std::vector<std::string> strings = std::vector<std::string>();

private:
};

int object::id = 2700;
std::string object::say(std::string string)
{
	// check if string already exists in vector
	if (std::find(strings.begin(), strings.end(), string) != strings.end())
	{
		std::cout << "Cannot print this string because it is already taken!" << std::endl;
	}
	else
	{
		object_map.insert(std::make_pair(string, id++));

		std::cout << "String (" << string << ") has ID: " << get_id(string) <<  std::endl;

		strings.push_back(string);
	}

	return string;
}

int object::get_id(std::string string)
{
	return object_map.at(string);
}

int main()
{
	object* _object = new object();

	_object->say("hello");
	_object->say("hello");
	_object->say("seven");
	_object->say("eleven");
	_object->say("eleven");
	_object->say("nine");

	object* object2 = new object();
	object2->say("yo man");

	std::cin.get();

	return 0;
}