#include "Game1.h"
#include "SpriteBatch.h"
#include "Font.h"
#include "Input.h"
#include "Agent.h"
#include <glm\glm.hpp>
#include <list>

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);	
	m_pAgent = new Agent(200, 200);	
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	delete m_pAgent;
}


void Game1::Update(float deltaTime)
{
	m_pAgent->Update(deltaTime);
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	m_pAgent->Draw(m_spritebatch);
	
	m_spritebatch->End();

}