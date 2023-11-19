#include <iostream>
#include <string>
#include <vector>

class Harvest
{
public:

	Harvest(std::string name, int weight, std::string color):name_(name), weight_(weight), color_(color) {}

	std::string GetName()
	{
		return this->name_;
	}

	int GetWeight()
	{
		return this->weight_;
	}

	std::string GetColor()
	{
		return this->color_;
	}

protected:
	std::string name_;
	int weight_;
	std::string color_;
};


class Plant
{
public:
	Plant(std::string size,int harvest_amount):size_(size), harvest_amount_(harvest_amount){}

	std::string GetSize()
	{
		return this->size_;
	}

	std::string GetColor()
	{
		return this->color_;
	}

	int GetHarvestAmount()
	{
		return this->harvest_amount_;
	}

	void SetHarvestAmount(int n)
	{
		harvest_amount_ = n;
	}
	virtual Harvest* harvest() = 0;
protected:
	
	std::string size_;
	std::string color_;
	int harvest_amount_;

};

class Apple :public Harvest
{
public:
	Apple(int weight, std::string color) :Harvest("apple", weight, color) {}

};

class AppleTree : public Plant {

public:
	AppleTree(std::string size, int amount) :Plant(size, amount) {}

	Harvest* harvest()
	{
		if (GetHarvestAmount() != 0)
		{
			SetHarvestAmount(GetHarvestAmount() - 1);
			return new Apple(50, "green");
		}
	}
};

class Raspberry :public Harvest
{
public:
	Raspberry(int weight, std::string color) :Harvest("raspberry", weight, color) {}

};

class RaspberryBush : public Plant {

public:
	RaspberryBush(std::string size, int amount) :Plant(size, amount) {}
	Harvest* harvest()
	{
		if (GetHarvestAmount() != 0)
		{
			SetHarvestAmount(GetHarvestAmount() - 1);

			return new Raspberry(20, "red");
		}
	}
};

class Orange :public Harvest
{
public:
	Orange(int weight, std::string color) :Harvest("raspberry", weight, color) {}

};

class OrangeTree : public Plant {

public:
	OrangeTree(std::string size, int amount) :Plant(size, amount) {}
	Harvest* harvest()
	{
		if (GetHarvestAmount() != 0)
		{
			SetHarvestAmount(GetHarvestAmount() - 1);

			return new Orange(100, "orange");
		}
	}
};

int main()
{
	std::vector<Plant*> plants;
	plants.push_back(new AppleTree("big", 30));
	plants.push_back(new RaspberryBush("medium", 35));
	plants.push_back(new OrangeTree("small", 10));

	for (auto& el : plants)
	{
		std::cout << "~~~\n";
		std::cout << "plant: " << el->harvest()->GetName() << "\n";
		std::cout << "size: " << el->GetSize() << "\n";
		std::cout << "amount of harvests: " << el->GetHarvestAmount() << "\n";

	}

	return 0;
}