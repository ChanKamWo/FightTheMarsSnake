#include "PlayScene.h"
#include "cocos2d.h"
#include "MarsSnake.h"
#include "EarthSnake.h"
#include "SnakeBase.h"
#include "SnakeNode.h"
#include "Food.h"
#include <vector>

USING_NS_CC;

bool PlayScene::init(){
    if ( !Layer::init() )
        return false;
    tiledMap = TMXTiledMap::create( mapsDirectory + "/lvl1.tmx" );
    addChild( tiledMap );
    for ( int i = 0; i < TILE_MAP_ROW_SIZE; i++ ){
        for ( int j = 0; j < TILE_MAP_COL_SIZE; j++ ){
            matrix[i][j] = tiledMap->getLayer( "obstacles" )->getTileGIDAt( gridToTiledCoordinate( Position( i, j ) ) );
        }
    }
    marsSnake = MarsSnake::createMarsSnake( this, Position( 12, 21 ), 2, 2 );
    addChild( marsSnake );
    snakes.push_back( marsSnake );
    earthSnake = EarthSnake::createEarthSnake( this, Position( 2, 3 ), 0, 2 );
    addChild( earthSnake );
    snakes.push_back( earthSnake );
    for ( auto snake : snakes ){
        addSnakeToMatrix( snake );
    }
    addFood();
    createScoreLayer();
    return true;
}

void PlayScene::addSnakeToMatrix( SnakeBase* snake ){
    for ( auto snakeNode : snake->getSnakeNodes() ){
        Position pos = snakeNode->getGridPosition();
        matrix[pos.row][pos.col] = snake->getClassifier();
    }
}

Position PlayScene::tiledToGridCoordinate( Point pos ){
    return Position( pos.y, pos.x );
}

Point PlayScene::gridToTiledCoordinate( Position pos ){
    return Point( pos.col, pos.row );
}

Scene* PlayScene::createScene(){
    auto scene = Scene::create();
    scene->addChild( PlayScene::create() );
    return scene;
}

void PlayScene::stop(){
    for ( auto snake : snakes ){
        snake->unschedule( schedule_selector( SnakeBase::move ) );
    }
}

void PlayScene::addFood(){
    std::vector<Position> grids;
    for ( int i = 0; i < TILE_MAP_ROW_SIZE; i++ ){
        for ( int j = 0; j < TILE_MAP_COL_SIZE; j++ ){
            if ( matrix[i][j] == 0 ){
                grids.push_back( Position( i, j ) );
            }
        }
    }
    auto pos = grids[rand( grids.size() )];
    food = Food::create();
    food->setGridPosition( pos );
    addChild( food );
}

void PlayScene::eliminateFood(){
    removeChild( food );
}

void PlayScene::createScoreLayer(){

    TTFConfig ttfConfig;
    ttfConfig.fontSize = 30;
    ttfConfig.fontFilePath = "fonts/Marker Felt.ttf";

    auto eLabel = Label::createWithTTF( ttfConfig, "Earth Snake" );
    auto mLabel = Label::createWithTTF( ttfConfig, "Mars Snake" );

    Size frameSize = Director::getInstance()->getOpenGLView()->getFrameSize();

    eLabel->setPosition( Point( frameSize.width*0.1, frameSize.height*0.95 ) );
    mLabel->setPosition( Point( frameSize.width*0.9, frameSize.height*0.95 ) );
    addChild( eLabel, 10 );
    addChild( mLabel, 10 );

    eScoreLabel = Label::createWithBMFont( "fonts/markerFelt.fnt", "Score: 0" );
    eScoreLabel->setPosition( Point( frameSize.width*0.1, frameSize.height*0.90 ) );
    addChild( eScoreLabel, 10 );

    mScoreLabel = Label::createWithBMFont( "fonts/markerFelt.fnt", "Score: 0" );
    mScoreLabel->setPosition( Point( frameSize.width*0.9, frameSize.height*0.90 ) );
    addChild( mScoreLabel, 10 );


    eSpeedLabel = Label::createWithBMFont( "fonts/markerFelt.fnt", "Speed: 0" );
    eSpeedLabel->setPosition( Point( frameSize.width*0.1, frameSize.height*0.85 ) );
    addChild( eSpeedLabel, 10 );

    mSpeedLabel = Label::createWithBMFont( "fonts/markerFelt.fnt", "Speed: 0" );
    mSpeedLabel->setPosition( Point( frameSize.width*0.9, frameSize.height*0.85 ) );
    addChild( mSpeedLabel, 10 );

    schedule( schedule_selector( PlayScene::updateScore ) );
}

void PlayScene::updateScore( float interval ){
    eScoreLabel->setString( "Score: " + earthSnake->getScore() );
    mScoreLabel->setString( "Score: " + marsSnake->getScore() );
    eSpeedLabel->setString( "Speed: " + ( int ) earthSnake->getSpeed() );
    mSpeedLabel->setString( "Speed: " + ( int ) marsSnake->getSpeed() );
}