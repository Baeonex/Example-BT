#pragma once
#include <glm\glm.hpp>
#include <list>

class Behaviour;
class SpriteBatch;
class Texture;

class Agent
{
public:
	Agent(float x, float y);
	~Agent();

	virtual void Update(float dt);
	virtual void Draw(SpriteBatch* spritebatch); 

	void SetAttack(bool state) {m_bAttack = state;}
	
protected:
	Behaviour* m_pBehaviourTree;
	Texture* m_pTexture;
	Texture* m_pAttackTexture;
	bool m_bAttack;

public:
	float m_maxSpeed;

	glm::vec2 m_acceleration;
	glm::vec2 m_velocity;
	glm::vec2 m_position;
};

