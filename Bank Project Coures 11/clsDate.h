#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<ctime>
#include<string>
#include"clsString.h" ; 
using namespace std;
class clsDate
{
private:
	int _Day;
	int _Month = 1;
	int _Year = 1990;


public:
	// Defualt Constractor : 
	clsDate() {

		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;

	}

	clsDate(string stringDate) {
		vector<string> vString = clsString::Split(stringDate, "/");
		_Day = stoi(vString[0]);
		_Month = stoi(vString[1]);
		_Year = stoi(vString[2]);
	}

	clsDate(short Days, short Month, short Year) {
		_Day = Days;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DateOrderInYear, short Year) {
		clsDate Date1 = GetDateFromDaysOrderInYear(DateOrderInYear, Year);
		_Day = Date1._Day;
		_Month = Date1._Month;
		_Year = Date1._Year;
	}
	// Day Set and Get : 
	void SetDay(short Days) {
		_Day = Days;
	}
	short GetDay() {
		return  _Day;
	}
	__declspec(property(get = GetDay, put = SetDay))short Day;

	//Month Set and Get : 
	void SetMonth(short Month) {
		_Month = Month;
	}
	short GetMonth() {
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	//Year  Set and Get : 
	void SetYear(short Year) {
		_Year = Year;
	}
	short GetYear() {
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear))short Year;

	void Print() {
		cout << DateToString() << endl;
	}
	static clsDate GetSystemDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Month, Year;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return clsDate(Day, Month, Year);
	}
	static string GetSystemDateTimeString() {
		time_t t = time(0); 
		tm* now = localtime(&t); 
		short Day, Month, Year, Hour, Minute, Secound; 
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1; 
		Day = now->tm_mday; 
		Hour = now->tm_hour; 
		Minute = now->tm_min; 
		Secound = now->tm_sec; 
		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + "-" + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Secound)); 
		}

	static bool IsValidDate(clsDate DateTime) {
		if (DateTime.Day < 1 || DateTime.Day > 31) return false;
		if (DateTime.Month < 1 || DateTime.Month > 31) return false;
		if (DateTime.Month == 2) {
			if (IsLeapYear(DateTime.Year)) {
				if (DateTime.Day > 29)  return false;
			}
			else {
				if (DateTime.Day > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInMonth(DateTime.Month, DateTime.Year);
		if (DateTime.Day > DaysInMonth)
			return false;
		return true;
	}

	bool IsValidDate() {
		return IsValidDate(*this);
	}

	static string DateToString(clsDate DateTime) {
		return to_string(DateTime._Day) + "/" + to_string(DateTime._Month) + "/" + to_string(DateTime.Year);
	}
	string DateToString() {
		return DateToString(*this);
	}

	static bool IsLeapYear(short Year) {
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	bool IsLeapYear() {
		return	IsLeapYear(_Year);
	}

	static short NumberOfDaysInAYear(short Year) {
		return IsLeapYear(Year) ? 365 : 364;
	}
	short NumberOfDaysInAYear() {
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year) {
		return NumberOfDaysInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear() {
		return NumberOfHoursInAYear(_Year);
	}

	static short NumberOfMinutesInAYear(short Year) {
		return NumberOfHoursInAYear(Year) * 60;
	}
	short NumberOfMinutesInAYear() {
		return NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecoundsInAYaer(short Year) {
		return	NumberOfMinutesInAYear(Year) * 60;
	}
	int NumberOfSecoundsInAYaer() {
		return NumberOfSecoundsInAYaer(_Year);
	}

	static short NumberOfDaysInMonth(short Month, short Year) {
		if (Month < 1 || Month > 12) {
			return 0;
		}
		short NumberOfDays[12] = { 31,28,31,30 ,31,30,31,30,31,31,30,31 };
		return Month == 2 ? IsLeapYear(Year) ? 29 : 28 : NumberOfDays[Month - 1];
	}
	short NumberOfDaysInMonth() {
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInAMonth(short Month, short Year) {
		return NumberOfDaysInMonth(Month, Year) * 24;
	}
	short NumberOfHoursInAMonth() {
		return NumberOfDaysInMonth(_Month, _Year) * 24;
	}

	static int NumberOfMinutesInAMonth(short Month, short Year) {
		return NumberOfHoursInAMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInAMonth() {
		return NumberOfHoursInAMonth(_Month, _Year) * 60;
	}

	static int NumberOfSecoundsInAMonth(short Month, short Year) {
		return NumberOfMinutesInAMonth(Month, Year) * 60;
	}
	int NumberOfSecoundsInAMonth() {
		return NumberOfMinutesInAMonth(_Month, _Year) * 60;
	}

	static short DayOfWeekOrder(short Days, short Month, short Year) {
		short a, m, y;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return  (Days + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeekOrder() {
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayShortName(short Day, short Month, short Year) {
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
	}
	string DayShortName() {
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder(_Day, _Month, Year)];
	}

	static string MonthShortName(short Month) {
		string Months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};
		return (Months[Month - 1]);
	}
	string MonthShortName() {
		return MonthShortName(_Month);
	}


	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInMonth(Month, Year);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(int Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}

		return;
	}
	void PrintYearCalendar()
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", _Year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, _Year);
		}

		return;
	}


	static clsDate GetDateFromDaysOrderInYear(short DaysOrderInYear, short Year) {
		clsDate DateTime;
		short RemainingDays = DaysOrderInYear;
		DateTime._Month = 1;
		short MonthDays;
		DateTime._Year = Year;
		while (true) {
			MonthDays = NumberOfDaysInMonth(DateTime._Month, Year);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				DateTime._Month++;
			}
			else {
				DateTime._Day = RemainingDays;
				break;
			}
		}
		return DateTime;
	}

	static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
		short TotalDays = 0;
		for (int i = 1; i <= Month - 1; i++) {
			TotalDays += NumberOfDaysInMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}
	short DaysFromTheBeginingOfTheYear()
	{


		short TotalDays = 0;

		for (int i = 1; i <= _Month - 1; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, _Year);
		}

		TotalDays += _Day;

		return TotalDays;
	}



	void AddDays(short Days)
	{


		short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(_Month, _Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;

				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}

		}


	}


	static bool IsDate1LessThanDate2(clsDate Date1, clsDate Date2) {
		return	(Date1._Year < Date2._Year) ? true :
			((Date1._Year == Date2._Year) ?
				(Date1._Month < Date2._Month) ? true :
				(Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false) : false);
	}
	bool IsDate1LessThanDate2(clsDate Date2) {
		return IsDate1LessThanDate2(*this, Date2);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	bool IsDateBeforeDate2(clsDate Date2)
	{
		//note: *this sends the current object :-) 
		return  IsDate1BeforeDate2(*this, Date2);

	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
		return  (Date1._Year == Date2._Year) ?
			((Date1._Month == Date2._Month) ?
				((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}
	bool IsDate1EqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}


	static bool IsLastDayInMonth(clsDate DateTime) {
		return (DateTime.Day == NumberOfDaysInMonth(DateTime._Month, DateTime._Year));
	}
	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}
	// 
	static bool IsLastMonthInYear(short Month) {
		return (Month == 12);
	}

	static clsDate AddOneDay(clsDate DateTime)
	{
		if (IsLastDayInMonth(DateTime))
		{
			if (IsLastMonthInYear(DateTime.Month))
			{
				DateTime.Month = 1;
				DateTime.Day = 1;
				DateTime.Year++;
			}
			else
			{
				DateTime.Day = 1;
				DateTime.Month++;
			}
		}
		else
		{
			DateTime.Day++;
		}

		return DateTime;
	}
	void AddOneDay()

	{
		*this = AddOneDay(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2) {
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		//this will take care of negative diff
		int Days = 0;
		short SawpFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates 
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;

		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}

		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool  IncludeEndDay = false) {
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static short CalculateMyAgeInDays(clsDate DateOfBirth) {
		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& DateTime)
	{

		for (int i = 1; i <= 7; i++)
		{
			DateTime = AddOneDay(DateTime);
		}

		return DateTime;
	}
	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}
	clsDate IncreaseDateByXWeeks(short Weeks, clsDate& DateTime)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			DateTime = IncreaseDateByOneWeek(DateTime);
		}
		return DateTime;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	clsDate IncreaseDateByOneMonth(clsDate& DateTime)
	{

		if (DateTime.Month == 12)
		{
			DateTime.Month = 1;
			DateTime.Year++;
		}
		else
		{
			DateTime.Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(DateTime.Month, DateTime.Year);
		if (DateTime.Day > NumberOfDaysInCurrentMonth)
		{
			DateTime.Day = NumberOfDaysInCurrentMonth;
		}

		return DateTime;
	}

	void IncreaseDateByOneMonth()
	{

		IncreaseDateByOneMonth(*this);

	}

	clsDate IncreaseDateByXDays(short Days, clsDate& DateTime)
	{

		for (short i = 1; i <= Days; i++)
		{
			DateTime = AddOneDay(DateTime);
		}
		return DateTime;
	}

	void IncreaseDateByXDays(short Days)
	{

		IncreaseDateByXDays(Days, *this);
	}

	clsDate IncreaseDateByXMonths(short Months, clsDate& DateTime)
	{

		for (short i = 1; i <= Months; i++)
		{
			DateTime = IncreaseDateByOneMonth(DateTime);
		}
		return DateTime;
	}

	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& DateTime)
	{
		DateTime.Year++;
		return DateTime;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	clsDate IncreaseDateByXYears(short Years, clsDate& DateTime)
	{
		DateTime.Year += Years;
		return DateTime;

	}

	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years);
	}

	clsDate IncreaseDateByOneDecade(clsDate& DateTime)
	{
		//Period of 10 years
		DateTime.Year += 10;
		return DateTime;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	clsDate IncreaseDateByXDecades(short Decade, clsDate& DateTime)
	{
		DateTime.Year += Decade * 10;
		return DateTime;
	}

	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	clsDate IncreaseDateByOneCentury(clsDate& DateTime)
	{
		//Period of 100 years
		DateTime.Year += 100;
		return DateTime;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	clsDate IncreaseDateByOneMillennium(clsDate& DateTime)
	{
		//Period of 1000 years
		DateTime.Year += 1000;
		return DateTime;
	}

	clsDate IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate DateTime)
	{
		if (DateTime.Day == 1)
		{
			if (DateTime.Month == 1)
			{
				DateTime.Month = 12;
				DateTime.Day = 31;
				DateTime.Year--;
			}
			else
			{

				DateTime.Month--;
				DateTime.Day = NumberOfDaysInMonth(DateTime.Month, DateTime.Year);
			}
		}
		else
		{
			DateTime.Day--;
		}

		return DateTime;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& DateTime)
	{

		for (int i = 1; i <= 7; i++)
		{
			DateTime = DecreaseDateByOneDay(DateTime);
		}

		return DateTime;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& DateTime)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			DateTime = DecreaseDateByOneWeek(DateTime);
		}
		return DateTime;
	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& DateTime)
	{

		if (DateTime.Month == 1)
		{
			DateTime.Month = 12;
			DateTime.Year--;
		}
		else
			DateTime.Month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(DateTime.Month, DateTime.Year);
		if (DateTime.Day > NumberOfDaysInCurrentMonth)
		{
			DateTime.Day = NumberOfDaysInCurrentMonth;
		}


		return DateTime;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate& DateTime)
	{

		for (short i = 1; i <= Days; i++)
		{
			DateTime = DecreaseDateByOneDay(DateTime);
		}
		return DateTime;
	}

	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate& DateTime)
	{

		for (short i = 1; i <= Months; i++)
		{
			DateTime = DecreaseDateByOneMonth(DateTime);
		}
		return DateTime;
	}

	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& DateTime)
	{

		DateTime.Year--;
		return DateTime;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate& DateTime)
	{

		DateTime.Year -= Years;
		return DateTime;
	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& DateTime)
	{
		//Period of 10 years
		DateTime.Year -= 10;
		return DateTime;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate& DateTime)
	{

		DateTime.Year -= Decades * 10;
		return DateTime;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& DateTime)
	{
		//Period of 100 years
		DateTime.Year -= 100;
		return DateTime;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& DateTime)
	{
		//Period of 1000 years
		DateTime.Year -= 1000;
		return DateTime;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}


	static short IsEndOfWeek(clsDate DateTime)
	{
		return  DayOfWeekOrder(DateTime.Day, DateTime.Month, DateTime.Year) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate DateTime)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(DateTime.Day, DateTime.Month, DateTime.Year);
		return  (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate DateTime)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur

	   /*
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex >= 5 && DayIndex <= 4);
	   */

	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !IsWeekEnd(DateTime);

	}

	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate DateTime)
	{
		return 6 - DayOfWeekOrder(DateTime.Day, DateTime.Month, DateTime.Year);
	}

	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{

		clsDate EndOfMontDate;
		EndOfMontDate.Day = NumberOfDaysInMonth(Date1.Month, Date1.Year);
		EndOfMontDate.Month = Date1.Month;
		EndOfMontDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfMontDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date1)
	{

		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);

	}

	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	//i added this method to calculate business days between 2 days
	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{

		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}

		return Days;

	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		/*short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}*/

		return CalculateBusinessDays(DateFrom, DateTo);

	}
	//above method is eough , no need to have method for the object

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = AddOneDay(DateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		/* if (IsDate1AfterDate2(Date1,Date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}


};

