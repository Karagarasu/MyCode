#include<iostream>
#include<memory>
class Entity
{
public:
	Entity()
	{
		std::cout << "创建了Entity！" << std::endl;
	}
	~Entity()
	{
		std::cout << "销毁了Entity！" << std::endl;
	}
	void print()
	{}
};
int main()
{
	{
		//std::shared_ptr<Entity> e0;
		std::weak_ptr<Entity> e0;
		{
			//std::unique_ptr<Entity> entity = std::make_unique<Entity>();
			//std::unique_ptr<Entity> e0 = entity; 无法赋值
			//entity->print();
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			//std::weak_ptr<Entity> weakEntity = sharedEntity;
			e0 = sharedEntity;
			
		}
	}
	system("pause");
	return 0;
}