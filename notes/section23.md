# Object Relationships

In C++, objects are often related to each other. For example, a `Car` object could have an `Engine` object as a member, and a `Bank` object could also have a `User` object as a dependency.

## Composition

In real-life, complex objects are often built from smaller, simpler objects. For example, a car is built using a metal frame, an engine, some tires, a transmission, a steering wheel, and a large number of other parts. A personal computer is built from a CPU, a motherboard, some memory, etc… Even you are built from smaller parts: you have a head, a body, some legs, arms, and so on. This process of building complex objects from simpler ones is called object composition.

Example:

```cpp
#include <iostream>
#include <string>
#include <string_view>

class CPU {
    private:
        int m_threads{};
        std::string m_model{};
        int m_cores{};
        double m_price{};

    public:
        CPU(int threads=0, std::string_view model="", int cores=0, double price=0.0)
            : m_model { model }
            , m_cores { cores }
            , m_price { price }
            , m_threads { threads } 
        {
        }

        friend std::ostream& operator<<(std::ostream& os, const CPU& cpu) {
            os << "Threads: " << cpu.m_threads << "\n" \
               << "Model: " << cpu.m_model << "\n" \
               << "Cores: " << cpu.m_cores << "\n" \
               << "Price: $" << cpu.m_price;
               
            return os;
        }
};

class PC {
    private:
        CPU m_cpu{};
        // less attributes for a reason

    public:
        explicit PC(CPU cpu)
        : m_cpu { cpu } { }

        CPU cpu() { return m_cpu; }
        void setCPU(CPU& cpu) { m_cpu = cpu; }
};

int main() {

    PC pc {  PC( CPU(16, "AMD Ryzen 7 7800x3D", 8, 550) ) };

    std::cout << pc.cpu() << "\n";

    return 0;
}
```

## Aggregation

To qualify as an aggregation, the dependent object and its parts must fit the following critera:

* The part (member) is part of the object (class)
* The part (member) can (if desired) belong to more than one object (class) at a time
* The part (member) does not have its existence managed by the object (class)
* The part (member) does not know about the existence of the object (class)

An example with a teacher and department class:

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Teacher
{
private:
  std::string m_name{};

public:
  Teacher(std::string_view name)
      : m_name{ name }
  {
  }

  const std::string& getName() const { return m_name; }
};

class Department
{
private:
  const Teacher& m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers

public:
  Department(const Teacher& teacher)
      : m_teacher{ teacher }
  {
  }
};

int main()
{
  // Create a teacher outside the scope of the Department
  Teacher bob{ "Bob" }; // create a teacher

  {
    // Create a department and use the constructor parameter to pass
    // the teacher to it.
    Department department{ bob };

  } // department goes out of scope here and is destroyed

  // bob still exists here, but the department doesn't

  std::cout << bob.getName() << " still exists!\n";

  return 0;
}
```

In this aggregation scenario, the `Teacher` class is the part and the `Department` class is the object.

Let's fact check all of these critera:

1. The part (member) is part of the object (class):

True, since the department class has a teacher member inside it

2. The part (member) can (if desired) belong to more than one object (class) at a time:

True, as one teacher can be in multiple departments at a time

3. The part (member) does not have its existence managed by the object (class):

True, since the department can get destroyed while still keeping the teacher in scope.

4. The part (member) does not know about the existence of the object (class):

True, since the teacher member has no direct link to the department, only the department knows about the teacher as a member.

## Association

Now let's look at another type of "has-a" relationship, association.

To qualify as an association, a member and an object must satisfy the critera:

* The associated object (member) is otherwise unrelated to the object (class)
* The associated object (member) can belong to more than one object (class) at a time
* The associated object (member) does not have its existence managed by the object (class)
* The associated object (member) may or may not know about the existence of the object (class)

Because associations are a broad type of relationship, they can be implemented in many different ways. However, most often, associations are implemented using pointers, where the object points at the associated object.

In this example, we’ll implement a bi-directional Doctor/Patient relationship, since it makes sense for the Doctors to know who their Patients are, and vice-versa.

Example:

```cpp
#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

// Since Doctor and Patient have a circular dependency, we're going to forward declare Patient
class Patient;

class Doctor
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patient{};

public:
	Doctor(std::string_view name) :
		m_name{ name }
	{
	}

	void addPatient(Patient& patient);

	// We'll implement this function below Patient since we need Patient to be defined at that point
	friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

	const std::string& getName() const { return m_name; }
};

class Patient
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Doctor>> m_doctor{}; // so that we can use it here

	// We're going to make addDoctor private because we don't want the public to use it.
	// They should use Doctor::addPatient() instead, which is publicly exposed
	void addDoctor(const Doctor& doctor)
	{
		m_doctor.push_back(doctor);
	}

public:
	Patient(std::string_view name)
		: m_name{ name }
	{
	}

	// We'll implement this function below to parallel operator<<(std::ostream&, const Doctor&)
	friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

	const std::string& getName() const { return m_name; }

	// We'll friend Doctor::addPatient() so it can access the private function Patient::addDoctor()
	friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient)
{
	// Our doctor will add this patient
	m_patient.push_back(patient);

	// and the patient will also add this doctor
	patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor)
{
	if (doctor.m_patient.empty())
	{
		out << doctor.m_name << " has no patients right now";
		return out;
	}

	out << doctor.m_name << " is seeing patients: ";
	for (const auto& patient : doctor.m_patient)
		out << patient.get().getName() << ' ';

	return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
	if (patient.m_doctor.empty())
	{
		out << patient.getName() << " has no doctors right now";
		return out;
	}

	out << patient.m_name << " is seeing doctors: ";
	for (const auto& doctor : patient.m_doctor)
		out << doctor.get().getName() << ' ';

	return out;
}

int main()
{
	// Create a Patient outside the scope of the Doctor
	Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };

	Doctor james{ "James" };
	Doctor scott{ "Scott" };

	james.addPatient(dave);

	scott.addPatient(dave);
	scott.addPatient(betsy);

	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';

	return 0;
}
```

## Dependencies

Lastly, let's look at the simplest relationship, dependencies.

A dependency occurs when one object invokes another object’s functionality in order to accomplish some specific task. This is a weaker relationship than an association, but still, any change to object being depended upon may break functionality in the (dependent) caller. A dependency is always a unidirectional relationship.

Example:

```cpp
#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0): m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point); // Point has a dependency on std::ostream here
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}

int main()
{
    Point point1 { 2.0, 3.0, 4.0 };

    std::cout << point1; // the program has a dependency on std::cout here

    return 0;
}
```
