#pragma once

#include <string>
#include <memory>
#include <vector>

class BlockSource;
class Level;
class Material;
class Player;
class EntityPos;
struct BlockPos;
class CompoundTag;
enum class ArmorSlot;
class EntityLink;
class EntityEvent;
class ItemInstance;
class ChangeDimensionPacket;
class ExplodeComponent;
class Dimension;
class Random;
class Entity;
class EntityLocation;
class PalleteColor;
class EntityUniqueID;
class EntityDefinitionGroup;
class EntityDefinitionIdentifier;
class VariantParameterList;
class SetEntityDataPacket;
class LevelSoundEvent;
class Brightness;
#include "../material/Material.h"
#include "EntityType.h"
#include "EntityRendererId.h"
#include "SynchedEntityData.h"
#include "EntityDamageSource.h"
#include "../level/dimension/dimensionId.h"
#include "../phys/AABB.h"
#include "../phys/Vec3.h"
#include "../phys/Vec2.h"
#include "../../util/Color.h"
#include "../../CommonTypes.h"

typedef std::vector<Entity*> EntityList;

class Entity
{
public:
	class InitializationMethod
	{
	};

	Entity(Level&);
	Entity(BlockSource&, const std::string&);
	Entity(EntityDefinitionGroup, const EntityDefinitionIdentifier&);
	
	virtual ~Entity();
	virtual void reloadHardcoded(InitializationMethod, const VariantParameterList&);
	virtual void reloadHardcodedClient(InitializationMethod, const VariantParameterList&);
	virtual void initializeComponents(InitializationMethod, const VariantParameterList&);
	virtual void reloadComponents(InitializationMethod, const VariantParameterList&);
	virtual bool hasComponent(const std::string&);
	virtual bool hasInventory() const;
	virtual void* getInventroy();
	virtual void reset();
	virtual int getOwnerEntityType();
	virtual void remove();
	virtual void setPos(const Vec3&);
	virtual Vec3& getPos() const;
	virtual Vec3& getPosOld() const;
	virtual Vec3& getPosExtrapolated(float) const;
	virtual Vec3& getVelocity() const;
	virtual void setRot(const Vec2&);
	virtual void move(const Vec3&);
	virtual void checkBlockCollisions(const AABB&);
	virtual void checkBlockCollisions();
	virtual bool canFy();
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(const Vec3&, const Vec2&, int);
	virtual void lerpMotion(const Vec3&);
	virtual void turn(const Vec2&, bool);
	virtual void interpolateTurn(const Vec2&);
	virtual void getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(Entity&) const;
	virtual float getRidingHeight();
	virtual float getRideHeight() const;
	virtual void startRiding(Entity&);
	virtual void addRider(Entity&);
	virtual void flagRiderToRemove(Entity&);
	virtual bool intersects(const Vec3&, const Vec3&);
	virtual bool isFree(const Vec3&, float);
	virtual bool isFree(const Vec3&);
	virtual bool isInWall() const;
	virtual bool isInvisible() const;
	virtual bool canShowNameTag();
	virtual bool canExistInPeaceFul() const;
	virtual void setNameTagVisible(bool);
	virtual std::string getNameTag() const;
	virtual std::string getFormattedNameTag() const;
	virtual void setNameTag(const std::string&);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(MaterialType) const;
	virtual void makeStuckInWeb();
	virtual float getHeadHeight() const;
	virtual float getCameraOffset();
	virtual float getShadowHeightOffs();
	virtual float getShadowRadius() const;
	virtual bool isSkyLit(float);
	virtual Brightness getBrightness(float) const;
	virtual bool interactPreventDefault();
	virtual void playerTouch(Player&);
	virtual void push(Entity&, bool);
	virtual void push(const Vec3&);
	virtual bool isImmobile() const;
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isPushable() const;
	virtual bool isPushableByPiston() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive() const;
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual void setTarget(Entity*);
	virtual void setOwner(EntityUniqueID);
	virtual void setSitting(bool);
	virtual void onTame();
	virtual void onFailedTame();
	virtual void onMate(Mob&);
	virtual bool shouldRender() const;
	virtual bool isInvurnerableTo(const EntityDamageSource&);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void onBounceStarted(const BlockPos&, const FullBlock&);
	virtual void feed();
	virtual void handleEntityEvent(EntityEvent, int);
	virtual int getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(FullBlock, int, float);
	virtual void spawnAtLocation(const ItemInstance&, float);
	virtual void killed(Entity*);
	virtual void awardKillScore(Entity&, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, const ItemInstance&);
	virtual void save(CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(const CompoundTag&);
	virtual void loadLinks(const CompoundTag&, std::vector<EntityLink, std::allocator<EntityLink>>&);
	virtual EntityType getEntityTypeId() const = 0;
	virtual bool acceptClientsideEntityData(Player&, const SetEntityDataPacket&);
	virtual void queryEntityRenderer();
	virtual long getSourceUniqueID();
	virtual void setOnFire(int);
	virtual AABB getHandleWaterAABB() const;
	virtual void handleInsidePortal(const BlockPos&);
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual DimensionId getDimensionId() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(const ChangeDimensionPacket&);
	virtual Player* getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void playSynchronizedSound(LevelSoundEvent, const Vec3&, int, bool);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity&) const;
	virtual float getEyeHeight() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool, bool);
	virtual void buildDebugInfo(std::string&) const;
	virtual bool hasOutputSignal(signed char) const;
	virtual int getOutputSignal() const;
	virtual std::string getDebugText(std::vector<std::string, std::allocator<std::string>>&);
	virtual void startSeenByPlayer(Player&);
	virtual void stopSeenByPlayer(Player&);
	virtual void* getMapDecorationRotation(Player&);
	virtual void* getRiderDecorationRotation(Player&);
	virtual float getYHeadRot() const;
	virtual bool isWorldBuilder();
	virtual bool isCreative() const;
	virtual void add(ItemInstance&);
	virtual void drop(const ItemInstance&, bool);
	virtual bool canDestroyBlock(const Block&) const;
	virtual void setAuxValue(int);
	virtual void setSize(float, float);
	virtual void setPos(const EntityPos&);
	virtual bool outOfWorld();
	virtual void markHurt();
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag*);
	virtual void addAdditionalSaveData(CompoundTag*);
	virtual void _playStepSound(const BlockPos&, int);
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(const Vec3&);
	virtual void updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void updateInsideBlock();
	virtual void onBlockCollision(int);
	virtual void* getLootTable() const;
	virtual void* getDefaultLootTable() const;
	virtual void _removeRider(std::string, bool);
	
	void _exitRide(const Entity&, float);
	void _findRider(Entity&) const;
	void _init();
	void _manageRiders(BlockSource&);
	void _sendLinkPacket(const EntityLink&) const;
	void _tryPlaceAt(const Vec3&);
	void _updateOwnerChunk();
	void buildForward() const;
	float distanceSqrToBlockPosCenter(const BlockPos&);
	float distanceTo(const Entity&);
	float distanceTo(const Vec3&);
	float distanceToSqr(const Entity&);
	float distanceToSqr(const Vec3&);
	void enableAutoSendPosRot();
	int getAirSupply() const;
	void getCenter(float);
	Dimension& getDimension() const;
	SynchedEntityData& getEntityData() const;
	SynchedEntityData& getEntityData();
	void getEyePos();
	Vec3& getInterpolatedPosition(float) const;
	Vec3& getInterpolatedPosition2(float) const;
	Vec2& getInterpolatedRotation(float) const;
	Level& getLevel();
	std::vector<EntityLink> getLinks() const;
	Vec2& getPortalEntranceDir() const;
	Vec3& getRandomPointInAABB(Random&);
	BlockSource& getRegion() const;
};

