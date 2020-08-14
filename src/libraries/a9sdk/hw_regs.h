#pragma once

#define HW_REG_FIELD(type, regname, fieldname) (type##_##regname##_##fieldname)

#define HW_REG(type, regname) (((volatile uint32_t *)type_BASE_ADDR) + (type##_##regname##_REG / 4))

#define HW_REG_STRUCT(type, regname) \
    ((volatile type##_##regname*)(((uint32_t*)type_BASE_ADDR) + (type##_##regname##_REG/4)))

#define HW_MB_REG(type, banknum, regname) (((volatile uint32_t*)type##banknum##_BASE_ADDR) + (type##_##regname##_REG/4))

#define HW_MB_REG_STRUCT(type, banknum, regname) \
    ((volatile type##_##regname*)HW_MB_REG(type,banknum, regname))

#define HW_MB_MERGE_REG(type, banknum, regname, mask, value) \
    *(HW_MB_REG(type, banknum, regname)) = ((*HW_MB_REG(type, banknum, regname)) & ~(mask)) | ((value) & (mask))
