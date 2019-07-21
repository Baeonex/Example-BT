#include "Agent.h"
#include "SpriteBatch.h"
#include "Input.h"
#include "Behaviour.h"
#include "Behaviours.h"
#include "Texture.h"

Agent::Agent(float x, float y) : m_position(x, y), m_pBehaviourTree(nullptr), m_bAttack(false)
{
	m_maxSpeed = 100;
	
	m_pTexture = new Texture("./Images/nodeTexture.png");	
	m_pAttackTexture = new Texture("./Images/nodeTextureHighlight.png");	
	
	// looks hideous, but basically builds the tree without using temp variables
	m_pBehaviourTree = 
		(new Selector())->add( 
			(new Sequence())->add(
				new MouseCloseCondition())->add(
				new AttackAction()))->add(
			(new Sequence())->add(
				new StopAttackAction())->add(
				new SeekAction()) );
				
}

Agent::~Agent()
{
	delete m_pTexture;
	delete m_pAttackTexture;

	if(m_pBehaviourTree != nullptr)
		delete m_pBehaviourTree;
}

void Agent::Update(float dt)
{
	
	if(m_pBehaviourTree != nullptr)
		m_pBehaviourTree->tick(this, dt);
		
	m_velocity.x += m_acceleration.x;
	m_velocity.y += m_acceleration.y;

	if (m_velocity.x > m_maxSpeed) {
		m_velocity.x = m_maxSpeed;
	}
	else if (m_velocity.x < -m_maxSpeed) {
		m_velocity.x < -m_maxSpeed;
	}
	if (m_velocity.y > m_maxSpeed) {
		m_velocity.y = m_maxSpeed;
	}
	else if (m_velocity.y < -m_maxSpeed) {
		m_velocity.y < -m_maxSpeed;
	}

	m_acceleration.x = 0;
	m_acceleration.y = 0;

	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;

}

void Agent::Draw(SpriteBatch* spritebatch)
{
	if(!m_bAttack)
		spritebatch->DrawSprite(m_pTexture, m_position.x, m_position.y);
	else
		spritebatch->DrawSprite(m_pAttackTexture, m_position.x, m_position.y);		
}
