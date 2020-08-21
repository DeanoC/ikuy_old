#pragma once

#define HW_REG_FIELD(type, regname, fieldname) type##_##regname##_##fieldname

#define HW_REG(type, regname) (((volatile uint32_t *)type##_BASE_ADDR) + (type##_##regname##_REG / 4))
#define HW_REG_GET_FIELD(type, regname, fieldname) ((*HW_REG(type, regname)) & (type##_##regname##_##fieldname##_MASK)) >> type##_##regname##_##fieldname##_LSHIFT
#define HW_REG_SET_BIT(type, regname, fieldname) *HW_REG(type, regname) = (((*HW_REG(type, regname)) & ~(type##_##regname##_##fieldname##_MASK)) | (type##_##regname##_##fieldname))
#define HW_REG_CLR_BIT(type, regname, fieldname) *HW_REG(type, regname) = ((*HW_REG(type, regname)) & ~(type##_##regname##_##fieldname##_MASK))
#define HW_REG_MERGE(type,  regname, mask, value) \
    *(HW_REG(type, regname)) = ((*HW_REG(type, regname)) & ~(mask)) | ((value) & (mask))
#define HW_REG_MERGE_FIELD(type,  regname, field, value) \
    HW_REG_MERGE(type, regname, (type##_##regname##_##field##_MASK), value)

#define HW_REG_MB(type, banknum, regname) (((volatile uint32_t*)type##banknum##_BASE_ADDR) + (type##_##regname##_REG/4))

#define HW_REG_MB_SET_BIT(type, banknum, regname, fieldname) *HW_REG_MB(type, banknum, regname) = ((*HW_REG_MB(type, banknum, regname)) & ~(type##_##regname##_##fieldname##_MASK)) | (type##_##regname##_##fieldname##_LSHIFT)
#define HW_REG_MB_CLR_BIT(type, banknum, regname, fieldname) *HW_REG_MB(type, banknum, regname) = (*HW_REG_MB(type, banknum, regname)) & ~(type##_##regname##_##fieldname##_MASK)
#define HW_REG_MB_MERGE(type, banknum, regname, mask, value) \
    *(HW_REG_MB(type, banknum, regname)) = ((*HW_REG_MB(type, banknum, regname)) & ~(mask)) | ((value) & (mask))

#define HW_REG_MB_MERGE_FIELD(type, banknum, regname, field, value) \
    HW_REG_MB_MERGE(type, banknum, regname, (type##_##regname##_##field##_MASK), value)
