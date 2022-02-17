#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include "engine/Engine.h"

class Test : public Engine {
public:
	Test();
	~Test() override;

	void init() override;

	void update() override;

	void handleLeftMouseClick(Point point) override;

	void handleBtnClick(int32_t idx) override;
};

#endif /* TEST_TEST_H_ */
