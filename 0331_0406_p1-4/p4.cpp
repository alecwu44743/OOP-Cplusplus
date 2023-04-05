#include <iostream>
using namespace std;

template <typename type_template>


class Queue{
    private:
        // int queue[100];
        type_template queue[100];
        int tailIndex;
        int pointTo;
    public:
        Queue(){
            this->tailIndex = 0;
            this->pointTo = 0;
        }

        void pushin(type_template element){
            this->queue[this->tailIndex] = element;
            this->tailIndex++;
        }

        type_template pushpout(){
            type_template temp = this->queue[this->pointTo];
            this->pointTo++;
            return temp;
        }

        int getPointIndex(){
            return this->pointTo;
        }

        bool isEmpty(){
            if(this->getPointIndex() == this->tailIndex){
                return true;
            }
            else{
                return false;
            }
        }

        ~Queue(){}
};


int main(){
    Queue<int> ivy;
    Queue<char> rina;

    int intRecycle;
    char charRecycle;

    ivy.pushin(1);
    cout << "[>] Push 1 into ivy queue" << endl;

    ivy.pushin(2);
    cout << "[>] Push 2 into ivy queue" << endl;

    ivy.pushin(3);
    cout << "[>] Push 3 into ivy queue" << endl;

    ivy.pushin(4);
    cout << "[>] Push 4 into ivy queue" << endl;

    intRecycle = ivy.pushpout();
    cout << "[<] Pop " << intRecycle << " out of ivy queue" << endl;

    ivy.pushin(5);
    cout << "[>] Push 5 into ivy queue" << endl;

    rina.pushin('a');
    cout << "[>] Push 'a' into rina queue" << endl;

    rina.pushin('b');
    cout << "[>] Push 'b' into rina queue" << endl;

    rina.pushin('c');
    cout << "[>] Push 'c' into rina queue" << endl;

    rina.pushin('d');
    cout << "[>] Push 'd' into rina queue" << endl;

    charRecycle = rina.pushpout();
    cout << "[<] Pop " << charRecycle << " out of rina queue" << endl;

    rina.pushin('e');
    cout << "[>] Push 'e' into rina queue" << endl;

    cout << "\n---------OUTPUT---------" << endl;

    // print the queue
    cout << "The ivy queue is: ";
    while(!ivy.isEmpty()){
        cout << ivy.pushpout() << " ";
    }
    cout << endl;

    cout << "The rina queue is: ";
    while(!rina.isEmpty()){
        cout << rina.pushpout() << " ";
    }
    cout << endl;

    return 0;
}