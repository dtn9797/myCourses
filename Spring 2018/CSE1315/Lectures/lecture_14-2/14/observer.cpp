#include <vector>
#include <functional>
#include <iostream>

// This is the interface specification for classes that observe the subject
class Observer_interface {
    public:
        virtual void notify() = 0;
};

// Here's an instance that prints "Notified" when the observed behavior occurs
class Observer : public Observer_interface {
    public:
        virtual void notify() override {
            std::cout << "Notified!" << std::endl;
        }
       
};

// The subject to be observed
// To observe the subject, an Observer (a class implementing the Observer_interface)
//   instance must be passed to register_observer
// As many Observers may register as desired
// When the behavior of interest occurs, Subject must call notify_observers, which
//   responds by calling the notify() method of all Observers
class Subject {
    public:
        void register_observer(Observer_interface& o) {
            observers.push_back(o);
        }
        void notify_observers() {
            for (Observer_interface& o : observers) {
        	o.notify();
            } 
        }
    private:
        // reference_wrapper is a C++ism required to create a vector of certain objects
        std::vector<std::reference_wrapper<Observer_interface>> observers;
};

int main() {
    // The subject to be observed. 
    // Call notify_observers() when a noteworthy event happens.
    Subject subject;

    // The observer watching the subject, waiting for a notification.
    Observer observer;

    // Register the observer with the subject
    subject.register_observer(observer);

    // Now, notify all observers that a noteworty event has happened.
    subject.notify_observers();
}
