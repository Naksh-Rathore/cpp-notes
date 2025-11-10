# Introduction to Inheritance

---

## What is Inheritance?

In C++ OOP (and any other programming language's OOP), inheritance involves creating new objects by directly acquiring the attributes and behaviors of other objects and then extending or specializing them. Like object composition, inheritance is everywhere in real life. When you were conceived, you inherited your parents genes, and acquired physical attributes from both of them, but then you added your own personality on top. Technological products inherit features from their predecessors.

Consider a dog and a cat. Although they are different species, they both are classified as house pets. That (house pet) is the "parent", and the "child" (the dogs and cats) inherit some attributes from the parents. We can also go one step further, since house pets are a "child" of animals. All house pets inherit features from an animal (the "parent"), so they are connected. This is the important part of inheritance, **connecting different objects by inheriting features from them**. 

Here is a diagram of the structure:

```
                [ Animals ]
               /    |      \
              /     |       \
             /      |        \ 
    [ Birds  ]   [ Pets ]   [ Reptiles ]
        |           |           |
        |           |           |
        |           |           |
    [ Parrot ]     [ Dog ]     [ Snake ]
```

Of course the diagram can be much more complicating, having more parent and child classes for each level, but this is just to give a basic visual.

## Implementing Inheritance in C++

Here's a simple class to show a generic person:

```cpp
class Person
{
// In this example, we're making our members public for simplicity
public:
    std::string m_name{};
    int m_age{};

    Person(std::string_view name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

};
```
Because this `Person` class is designed to represent a generic person, we’ve only defined members that would be common to any type of person. Every person has a name and age, so those are represented here.

Suppose we want to represent a more specialized type of `Person`, like a baseball player.

Here is an incomplete class for said baseball player:

```cpp
class BaseballPlayer
{
// In this example, we're making our members public for simplicity
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
       : m_battingAverage{battingAverage}, m_homeRuns{homeRuns}
    {
    }
};
```
Later on, we also may want to keep track of a baseball player’s name and age, and we already have that information as part of our `Person` class.

There are 3 options on how to do that:

1. Add name and age to the BaseballPlayer class directly as members. This is probably the worst choice, as we’re duplicating code that already exists in our Person class. Any updates to `Person` will have to be made in `BaseballPlayer` too.

2. Add `Person` as a member of `BaseballPlayer` using composition. But we have to ask ourselves, “does a `BaseballPlayer` have a `Person`”? No, it doesn’t. So this isn’t the right paradigm.

3. Have `BaseballPlayer` inherit those attributes from `Person`. Remember that inheritance represents an is-a relationship. Is a `BaseballPlayer` a 
`Person`? Yes, it is. So inheritance is a good choice here.

To utilize the third option (having the `BaseballPlayer` class inherit from `Person`), we can use C++'s built-in inheritance features.

Syntax:

```cpp
class Child : public Parent {
    private:
        // Special private attributes of the child

    public:
        Child(params) 
            : Parent(params) // Parameters of the parent class
            // Set special private attributes of the child
        {
        }

        // Set special member functions of the child
};
```

Now here is the `BaseballPlayer` class with inheritance:

```cpp
// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0, std::string_view name, int age)
       : Person(name, age)
       , m_battingAverage{battingAverage}, m_homeRuns{homeRuns}
    {
    }
};
```

