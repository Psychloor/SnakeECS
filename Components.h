#pragma once

#include <vector>
#include <SFML/System/Time.hpp>

enum class Direction
{
	None,
	North,
	East,
	South,
	West
};

enum class FruitType
{
	Regular,
	Special
};

struct FruitSpawner
{
	sf::Time remaining;
};

struct Position
{
	char x;
	char y;
};

struct Fruit
{
	FruitType type;
};

struct Score
{
	char amount;
};

struct Segment
{
	explicit Segment(const Position position)
	{
		current = position;
		previous = position;
	}

	void setPosition(const Position position)
	{
		previous = current;
		current = position;
	}


	[[nodiscard]] Position currentPosition() const
	{
		return current;
	}

	[[nodiscard]] Position previousPosition() const
	{
		return previous;
	}

private:
	Position current{};
	Position previous{};
};

struct Snake
{
	std::vector<Segment> segments{};
	Direction direction = Direction::None;
	char extensionsLeft = 0;
};

struct Time
{
	sf::Time time = sf::Time::Zero;
};
