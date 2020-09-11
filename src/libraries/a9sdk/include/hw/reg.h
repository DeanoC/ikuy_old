#pragma once

#define HW_REG_FIELD(type, reg, field) (type##_##reg##_##field)
#define HW_REG_FIELD_LSHIFT(type, reg, field) (type##_##reg##_##field##_LSHIFT)
#define HW_REG_FIELD_MASK(type, reg, field) (type##_##reg##_##field##_MASK)

#define HW_MAKE_REG_FIELD_VAL(type, reg, field, value) (value << HW_REG_FIELD_LSHIFT(type, reg, field))

#define HW_REG(type, reg) (((volatile uint32_t *)type##_BASE_ADDR) + (type##_##reg##_REG / 4))
#define HW_REG_ARRAY(type, reg, index) ( ((volatile uint32_t *)type##_BASE_ADDR) + (type##_##reg##_REG / 4) + index)

#define HW_REG_GET_FIELD(type, reg, field) ((*HW_REG(type, reg)) & (HW_REG_FIELD_MASK(type, reg, field))) >> HW_REG_FIELD_LSHIFT(type, reg, field)
#define HW_REG_ARRAY_GET_FIELD(type, reg, index, field) ((*HW_REG_ARRAY(type, reg, index)) & (HW_REG_FIELD_MASK(type, reg, field))) >> HW_REG_FIELD_LSHIFT(type, reg, field)

#define HW_REG_SET_BIT(type, reg, field) *HW_REG(type, reg) = (((*HW_REG(type, reg)) & ~HW_REG_FIELD_MASK(type, reg, field)) | HW_REG_FIELD(type, reg, field))
#define HW_REG_CLR_BIT(type, reg, field) *HW_REG(type, reg) = ((*HW_REG(type, reg)) & ~HW_REG_FIELD_MASK(type, reg, field))
#define HW_REG_GET_BIT(type, reg, field) (!!((*HW_REG(type, reg)) & HW_REG_FIELD_MASK(type, reg, field)))

#define HW_REG_MERGE(type,  reg, mask, value) \
    *(HW_REG(type, reg)) = ((*HW_REG(type, reg)) & ~(mask)) | ((value) & (mask))
#define HW_REG_ARRAY_MERGE(type, reg, index, mask, value) \
    *(HW_REG_ARRAY(type, reg, index)) = ((*HW_REG_ARRAY(type, reg, index)) & ~(mask)) | ((value) & (mask))

#define HW_REG_MERGE_FIELD(type, reg, field, value) \
    HW_REG_MERGE(type, reg, HW_REG_FIELD_MASK(type, reg, field), value)

#define HW_REG_ARRAY_MERGE_FIELD(type, reg, index, field, value) \
    HW_REG_ARRAY_MERGE(type, reg, index, HW_REG_FIELD_MASK(type, reg, field), value)

#define HW_REG_MB(type, bank, reg) (((volatile uint32_t*)type##bank##_BASE_ADDR) + (type##_##reg##_REG/4))

#define HW_REG_MB_SET_BIT(type, bank, reg, field) *HW_REG_MB(type, bank, reg) = ((*HW_REG_MB(type, bank, reg)) & ~HW_REG_FIELD_MASK(type, reg, field)) | HW_REG_FIELD_LSHIFT(type, reg, field)
#define HW_REG_MB_CLR_BIT(type, bank, reg, field) *HW_REG_MB(type, bank, reg) = (*HW_REG_MB(type, bank, reg)) & ~HW_REG_FIELD_MASK(type, reg, field)
#define HW_REG_MB_GET_BIT(type, bank, reg, field) (!!((*HW_REG_MB(type, bank, reg)) & HW_REG_FIELD_MASK(type, reg, field)))

#define HW_REG_MB_MERGE(type, bank, reg, mask, value) \
    *(HW_REG_MB(type, bank, reg)) = ((*HW_REG_MB(type, bank, reg)) & ~(mask)) | ((value) & (mask))

#define HW_REG_MB_MERGE_FIELD(type, bank, reg, field, value) \
    HW_REG_MB_MERGE(type, bank, reg, HW_REG_FIELD_MASK(type, reg, field), value)
