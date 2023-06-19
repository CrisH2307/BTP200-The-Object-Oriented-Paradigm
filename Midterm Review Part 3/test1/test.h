//! SAMPLE 2: TEAM PROJECT
//! 
#include <iostream>
namespace project
{
	class Team
	{
		char m_name[1024];
		double m_hour;
		int m_number;
	public:
		Team();
		Team(const char* name, double hour);
		double avgHour() const;
		void add(const char* name, double hour);
		void addHours(const char* name, double hours);		
		operator int()const;
		~Team();

	};
	std::ostream& operator<<(std::ostream& os, const Team& mem);

}