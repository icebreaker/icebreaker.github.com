#include "Lera3D.h"

class Cube : public leraIMesh
{
	public:
		Cube( leraIMesh *cube = NULL, bool rotating = false )
		{
			this->cube = cube;
			this->rotating = rotating;
		};
		
		virtual void render( float elapsedTime )
		{
			// always update
			this->update( elapsedTime );
			
			glPushMatrix();
				glTranslatef(currPos[0],currPos[1],currPos[2]);
				
				if ( rotating )
				{
					float frame = elapsedTime / 10.0f;
					glRotatef(frame + rotation[0],1.0f,0.0f,0.0f);
					glRotatef(frame + rotation[1],0.0f,1.0f,0.0f);
					glRotatef(frame + rotation[2],0.0f,0.0f,1.0f);
				}
				else
				{
					glRotatef(rotation[0],1.0f,0.0f,0.0f);
					glRotatef(rotation[1],0.0f,1.0f,0.0f);
					glRotatef(rotation[2],0.0f,0.0f,1.0f);
				}
				
				glColor3fv(currCol);

				cube->render();
				
			glPopMatrix();
		};
		
		virtual void update( float elapsedTime )
		{
			float frame = elapsedTime / 500.0f;
			
			diff_position[2] = sinf( position[2] + frame ) * cosf( position[2] + frame ) * 2.0f;
			
			leraVecSet( diff_color, diff_position[2], diff_position[2], diff_position[2] );
			leraVecDiv( diff_color, 4.0f * sinf(elapsedTime/1000.0f) );
			
			leraVecCpy(currPos, position);
			leraVecAdd(currPos, diff_position);
			
			leraVecCpy(currCol, color);
			leraVecAdd(currCol, diff_color);
		};

		virtual void setColor( leraVec3 color )
		{
			leraVecCpy( this->color, color );	
		};
		
		virtual void setColor( float r, float g, float b )
		{
			leraVec3 color = { r, g, b };
			this->setColor( color );
		};
		
	protected:
		leraIMesh *cube;
	
		leraVec3 color;
		leraVec3 diff_color;

		leraVec3 diff_position;
		
		leraVec3 currPos;
		leraVec3 currCol;
		
		bool rotating;
};

class CubeSphere
{
	#define CUBE_SIZE 		0.275f
	#define DETAIL_NUMAROS 	40.0f
	#define DETAIL_ARO 		40.0f
	
	public:
		CubeSphere( const float size = CUBE_SIZE, bool randomRot = false )
		{
			cube = leraIMesh::getCube( size );
			rotating = false;
			
			float alpha_inc = leraPI / DETAIL_NUMAROS;
			float theta_inc = 2 * leraPI / DETAIL_ARO;

			// move on Z
			center[2] = -30.0f;
			
			if( randomRot )
				leraRandomize();
			
			for ( float alpha = - leraPI / 2; alpha < leraPI / 2; alpha+=alpha_inc )
			{
				for ( float theta = 0; theta < 2 * leraPI; theta+=theta_inc )
				{
					float nx =  cosf( alpha ) * sinf( theta );  
					float ny =  cosf( alpha ) * cosf( theta );
					float nz = -sinf( alpha );
					
					Cube *c = new Cube( cube, rotating );
					c->setPosition( nx * 6.0f, ny * 6.0f, nz * 6.0f );
					c->setColor( sinf( theta * nx ), ny, 0.0f );
					if( randomRot )
						c->setRotation( leraRandom(360), leraRandom(360), leraRandom(360) );
					cubes.push_back(c);
				}
			}
		};
		
		virtual void render( float elapsedTime )
		{
			glPushMatrix();
				
				glTranslatef(center[0],center[1],center[2]);

				vector<Cube *>::const_iterator it;
				for( it = cubes.begin(); it != cubes.end(); ++it )
					(*it)->render( elapsedTime );
				
			glPopMatrix();
		};
		
		virtual ~CubeSphere( )
		{
			vector<Cube *>::iterator it;
			for( it = cubes.begin(); it != cubes.end(); ++it )
				leraFree( (*it) );
					
			cubes.clear();
			
			leraFree( cube );
		};
		
	private:
		leraIMesh *cube;
		vector< Cube * > cubes;
	
		bool rotating;
		leraVec3 center;
};

class App : public leraIApp
{
	public:
		bool beforeInit( void )
		{	
			leraEnv &env = leraEnv::getInstance();
			
			//env.setInt("width",1024);
			//env.setInt("height",768);
			env.setBool("grabInput",true);
			env.setBool("centerMouse",true);
			env.setBool("showMouse",false);
			env.setString("title","Cubes Demo");
			env.setBool("sndNoAudio",true);
			//env.setBool("fullScreen",true);

			return true;
		};

		bool init( void )
		{	
			leraRenderer &renderer = leraRenderer::getInstance();
			renderer.enableLights();
			renderer.enableColorMaterials();
			renderer.enableCulling();
			//renderer.enableWireframe();

			light = new leraLight;
			light->enable();

			camera = new leraCamera;
			cube = new CubeSphere;
			
			return true;
		};

		bool shutdown( void )
		{
			leraFree( light 	);
			leraFree( camera 	);
			leraFree( cube 		);

			return true;
		};

		bool render( float elapsedTime, int fps )
		{
			leraRenderer &renderer = leraRenderer::getInstance();
			
			renderer.begin();

				camera->update();
				cube->render( leraGetTicks() * 0.8 );
								
			renderer.end();
			
			return true;
		};

		bool think( float elapsedTime )
		{
			leraInputManager &inputManager = leraInputManager::getInstance();
			
			if( inputManager.isKeyDown( Key::vkEscape ) )
				return false;
			
			if( inputManager.isKeyDown( Key::vkSpace ) )
			{
				leraRenderer &renderer = leraRenderer::getInstance();
				renderer.takeScreenshot();
				return true;
			}
			
			float delta = ( elapsedTime / 30 );

			if( inputManager.isKeyDown( Key::vkW ) )
				camera->move( delta * -0.5f );

			if( inputManager.isKeyDown( Key::vkS ) )
				camera->move( delta * 0.5f );

			if( inputManager.isKeyDown( Key::vkA ) )
				camera->strafe( delta * -0.5f );
			
			if( inputManager.isKeyDown( Key::vkD ) )
				camera->strafe( delta * 0.5f );

			camera->rotateY( inputManager.getMouseDX() * 0.05f );
			camera->rotateX( inputManager.getMouseDY() * 0.05f );
				
			return true;
		};
	
	private:
		leraCamera *camera;
		leraLight *light;
		
		CubeSphere *cube;
};	
	
__main( App );

