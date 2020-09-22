/*
 * 使用原型实例指定待创建对象的类型，并且通过复制这个原型来创建型的对象
 * 
*/ 

#include <iostream>

class WorkModel {
public:
    char *modelName;
    void setWorkModelName(char *iName) {
        this->modelName = iName;
    }
};

class PrototypeWork {
public:
    PrototypeWork() {};
    virtual PrototypeWork *clone() = 0;
};

class ConcreteWork : public PrototypeWork {
public:
    ConcreteWork() {};
    ConcreteWork(char* iName, int iIdNum, char* modelName) {
        this->name = iName;
        this->idNum = iIdNum;
        this->workModel = new WorkModel();
        this->workModel->setWorkModelName(modelName);
    }

    ConcreteWork *clone() {
        ConcreteWork *work = new ConcreteWork();
        work->setName(this->name);
        work->setIdNum(idNum);
        work->setModel(this->workModel);
        return work;
    }

    void setName(char *iName) {
        this->name = iName;
    }

    void setIdNum(int idNum) {
        this->idNum = idNum;
    }

    void setModel(WorkModel* iWorkModel) {
        this->workModel = iWorkModel;
    }

    void printWorkInfo() {
        printf("name: %s\t\n", this->name);
        printf("idNum: %d\t\n", this->idNum);
        printf("modelName:%s\t\n", this->workModel->modelName);
    }

private:
    char* name;
    int idNum;
    WorkModel* workModel;
};

void shallow_copy() {
    ConcreteWork* singleWork = new ConcreteWork("Single", 1001, "Single_Model");
    std::cout << "Single 的作业" << std::endl;
    singleWork->printWorkInfo();

    std::cout << std::endl << "LiuYang 抄作业" << std::endl;
    ConcreteWork *liuyangWork = singleWork;
    std::cout << "LiuYang 的作业" << std::endl;
    liuyangWork->printWorkInfo();

    std::cout << std::endl << "抄完改名字和学号" << std::endl;
    liuyangWork->setIdNum(1002);
    liuyangWork->setName("LiuYang");
    WorkModel* model = new WorkModel();
    model->setWorkModelName("LiuYang_Model");
    liuyangWork->setModel(model);
    liuyangWork->printWorkInfo();
    std::cout << std::endl << "Single 的作业" << std::endl;
    singleWork->printWorkInfo();
}

void deep_copy() {
    ConcreteWork *single = new ConcreteWork("Single", 1001, "Single_Model");
    std::cout << "Single 的作业" << std::endl;

    ConcreteWork *liuyang = single->clone();
    std::cout << "Liuyang 的作业" << std::endl;

    std::cout << "改学号" << std::endl;
    liuyang->setName("Liuyang");
    liuyang->setIdNum(1002);
    auto liuyangModel = new WorkModel();
    liuyangModel->setWorkModelName("Liuyang_Model");
    liuyang->setModel(liuyangModel);

    std::cout << "Single 的作业" << std::endl;
    single->printWorkInfo();
    std::cout << std::endl << "Liuyang 的作业" << std::endl;
    liuyang->printWorkInfo();
}

int main() {
    deep_copy();
}