#pragma once
class Animals : public CObject
{
public:
	Animals() {};
	Animals(int id,CString name, int number_of_legs) :id(id),name(name), number_of_legs(number_of_legs) {}
	virtual ~Animals() {};
	virtual int Get_number_of_legs() const = 0;
	virtual CString Get_name() const = 0;
	virtual CString Voice() const = 0;
	virtual CString Habitat() const = 0;
	virtual void Serialize(CArchive &) = 0;
	int getId() { return id; }
protected:
	int id;
	CString name;
	int number_of_legs;
};


class Tadpole : public Animals 
{
	DECLARE_SERIAL(Tadpole)
public:
	Tadpole(): Animals(){};
	Tadpole(int id, CString name, int number_of_legs) : Animals(id,name, number_of_legs) {}

	virtual CString Voice()const
	{
		return _T("glu glu...");
	}

	virtual CString Habitat()const
	{
		return _T("In the water");
	}

	virtual int Get_number_of_legs()const
	{
		return (number_of_legs);
	}

	virtual CString Get_name()const
	{
		return (this->name);
	}
	virtual void Serialize(CArchive &);
};


class Frog : public Tadpole
{
	DECLARE_SERIAL(Frog)
public:
	Frog() :Tadpole() {};
	Frog(int id, CString name, int number_of_legs) : Tadpole(id,name, number_of_legs) {}

	CString Abilities() const
	{
		return _T("I Can jump!");
	}

	virtual CString Voice() const
	{
		return _T("Rabbit");
	}

	virtual  CString  Habitat() const
	{
		return _T("In the water and land");
	}

	virtual int Get_number_of_legs() const
	{
		return (this->number_of_legs);
	}

	virtual CString Get_name() const
	{
		return (this->name);
	}

	virtual void Serialize(CArchive &);
};

class Larva : public Animals
{
	DECLARE_SERIAL(Larva)
public:
	Larva(): Animals(){};
	Larva(int id, CString name, int number_of_legs) : Animals(id, name, number_of_legs) {}

	virtual CString Voice()const
	{
		return _T("Shhhh");
	}

	virtual CString Habitat()const
	{
		return _T("In the forest");
	}

	virtual int Get_number_of_legs()const
	{
		return (number_of_legs);
	}

	virtual CString Get_name()const
	{
		return (this->name);
	}
	virtual void Serialize(CArchive &);
};

class Cocoon : public Larva
{
	DECLARE_SERIAL(Cocoon)

public:
	Cocoon(): Larva() {};
	Cocoon(int id, CString name, int number_of_legs) : Larva(id,name, number_of_legs) {}

	virtual CString Voice()const
	{
		return _T("Shhhh");
	}

	virtual CString Habitat()const
	{
		return _T("On the leaf");
	}

	virtual int Get_number_of_legs()const
	{
		return (number_of_legs);
	}

	virtual CString Get_name()const
	{
		return (this->name);
	}
	virtual void Serialize(CArchive &);
};

class Butterfly : public Cocoon
{
	DECLARE_SERIAL(Butterfly)
public:
	Butterfly() : Cocoon(){};
	Butterfly(int id, CString name, int number_of_legs) : Cocoon(id,name, number_of_legs) {}

	virtual CString Voice()const
	{
		return _T("Shhhh");
	}

	virtual CString Habitat()const
	{
		return _T("In the air");
	}

	virtual int Get_number_of_legs()const
	{
		return (number_of_legs);
	}

	virtual CString Get_name()const
	{
		return (this->name);
	}
	CString Abilities() const
	{
		return _T("I Can fly!");
	}
	virtual void Serialize(CArchive &);
};