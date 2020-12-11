#include "stdafx.h"
#include "Animals.h"

IMPLEMENT_SERIAL(Butterfly, CObject, 1)
void Butterfly::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << id << name << number_of_legs;
	}
	else
	{
		archive >> name >> number_of_legs;
	}
}

IMPLEMENT_SERIAL(Cocoon, CObject, 1)
void Cocoon::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << id << name << number_of_legs;
	}
	else
	{
		archive >> name >> number_of_legs;
	}
}

IMPLEMENT_SERIAL(Frog, CObject, 1)
void Frog::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << id << name << number_of_legs;
	}
	else
	{
		archive >> name >> number_of_legs;
	}
}

IMPLEMENT_SERIAL(Larva, CObject, 1)
void Larva::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << id << name << number_of_legs;
	}
	else
	{
		archive >> name >> number_of_legs;
	}
}

IMPLEMENT_SERIAL(Tadpole, CObject, 1)
void Tadpole::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << id << name << number_of_legs;
	}
	else
	{
		archive >> name >> number_of_legs;
		
	}
}