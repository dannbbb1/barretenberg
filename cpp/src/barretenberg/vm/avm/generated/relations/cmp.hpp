// AUTOGENERATED FILE
#pragma once

#include "barretenberg/relations/relation_parameters.hpp"
#include "barretenberg/relations/relation_types.hpp"

namespace bb::Avm_vm {

template <typename FF_> class cmpImpl {
  public:
    using FF = FF_;

    static constexpr std::array<size_t, 28> SUBRELATION_PARTIAL_LENGTHS = { 3, 4, 2, 3, 5, 3, 3, 3, 3, 3, 3, 3, 3, 5,
                                                                            5, 3, 2, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3 };

    template <typename ContainerOverSubrelations, typename AllEntities>
    void static accumulate(ContainerOverSubrelations& evals,
                           const AllEntities& new_term,
                           [[maybe_unused]] const RelationParameters<FF>&,
                           [[maybe_unused]] const FF& scaling_factor)
    {
        const auto cmp_A_GT_B = ((new_term.cmp_input_a - new_term.cmp_input_b) - FF(1));
        const auto cmp_B_GTE_A = (new_term.cmp_input_b - new_term.cmp_input_a);
        const auto cmp_DIFF = (new_term.cmp_input_a - new_term.cmp_input_b);
        const auto cmp_POW_128 = FF(uint256_t{ 0UL, 0UL, 1UL, 0UL });
        const auto cmp_P_LO = FF(uint256_t{ 4891460686036598784UL, 2896914383306846353UL, 0UL, 0UL });
        const auto cmp_P_HI = FF(uint256_t{ 13281191951274694749UL, 3486998266802970665UL, 0UL, 0UL });
        const auto cmp_A_SUB_B_LO =
            (((new_term.cmp_a_lo - new_term.cmp_b_lo) - FF(1)) + (new_term.cmp_borrow * cmp_POW_128));
        const auto cmp_A_SUB_B_HI = ((new_term.cmp_a_hi - new_term.cmp_b_hi) - new_term.cmp_borrow);
        const auto cmp_B_SUB_A_LO = ((new_term.cmp_b_lo - new_term.cmp_a_lo) + (new_term.cmp_borrow * cmp_POW_128));
        const auto cmp_B_SUB_A_HI = ((new_term.cmp_b_hi - new_term.cmp_a_hi) - new_term.cmp_borrow);
        const auto cmp_IS_GT = (new_term.cmp_op_gt * new_term.cmp_result);

        {
            using Accumulator = typename std::tuple_element_t<0, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_sel_rng_chk *
                        (new_term.cmp_range_chk_clk - ((new_term.cmp_clk * FF(256)) + new_term.cmp_cmp_rng_ctr)));
            tmp *= scaling_factor;
            std::get<0>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<1, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_op_non_ff_gt * ((new_term.cmp_diff - (cmp_A_GT_B * new_term.cmp_result)) -
                                                     (cmp_B_GTE_A * (FF(1) - new_term.cmp_result))));
            tmp *= scaling_factor;
            std::get<1>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<2, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_sel_cmp - ((new_term.cmp_op_eq + new_term.cmp_op_gt) + new_term.cmp_op_non_ff_gt));
            tmp *= scaling_factor;
            std::get<2>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<3, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_result * (FF(1) - new_term.cmp_result));
            tmp *= scaling_factor;
            std::get<3>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<4, ContainerOverSubrelations>;
            auto tmp =
                (new_term.cmp_op_eq * (((cmp_DIFF * ((new_term.cmp_result * (FF(1) - new_term.cmp_op_eq_diff_inv)) +
                                                     new_term.cmp_op_eq_diff_inv)) -
                                        FF(1)) +
                                       new_term.cmp_result));
            tmp *= scaling_factor;
            std::get<4>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<5, ContainerOverSubrelations>;
            auto tmp =
                (new_term.cmp_op_gt * (new_term.cmp_input_a - (new_term.cmp_a_lo + (cmp_POW_128 * new_term.cmp_a_hi))));
            tmp *= scaling_factor;
            std::get<5>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<6, ContainerOverSubrelations>;
            auto tmp =
                (new_term.cmp_op_gt * (new_term.cmp_input_b - (new_term.cmp_b_lo + (cmp_POW_128 * new_term.cmp_b_hi))));
            tmp *= scaling_factor;
            std::get<6>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<7, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_p_a_borrow * (FF(1) - new_term.cmp_p_a_borrow));
            tmp *= scaling_factor;
            std::get<7>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<8, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_op_gt * (new_term.cmp_p_sub_a_lo - ((cmp_P_LO - new_term.cmp_a_lo) +
                                                                         (new_term.cmp_p_a_borrow * cmp_POW_128))));
            tmp *= scaling_factor;
            std::get<8>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<9, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_op_gt *
                        (new_term.cmp_p_sub_a_hi - ((cmp_P_HI - new_term.cmp_a_hi) - new_term.cmp_p_a_borrow)));
            tmp *= scaling_factor;
            std::get<9>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<10, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_p_b_borrow * (FF(1) - new_term.cmp_p_b_borrow));
            tmp *= scaling_factor;
            std::get<10>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<11, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_op_gt * (new_term.cmp_p_sub_b_lo - ((cmp_P_LO - new_term.cmp_b_lo) +
                                                                         (new_term.cmp_p_b_borrow * cmp_POW_128))));
            tmp *= scaling_factor;
            std::get<11>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<12, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_op_gt *
                        (new_term.cmp_p_sub_b_hi - ((cmp_P_HI - new_term.cmp_b_hi) - new_term.cmp_p_b_borrow)));
            tmp *= scaling_factor;
            std::get<12>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<13, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_op_gt * (new_term.cmp_res_lo -
                                              ((cmp_A_SUB_B_LO * cmp_IS_GT) + (cmp_B_SUB_A_LO * (FF(1) - cmp_IS_GT)))));
            tmp *= scaling_factor;
            std::get<13>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<14, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_op_gt * (new_term.cmp_res_hi -
                                              ((cmp_A_SUB_B_HI * cmp_IS_GT) + (cmp_B_SUB_A_HI * (FF(1) - cmp_IS_GT)))));
            tmp *= scaling_factor;
            std::get<14>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<15, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_sel_rng_chk * (FF(1) - new_term.cmp_sel_rng_chk));
            tmp *= scaling_factor;
            std::get<15>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<16, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_sel_rng_chk_shift - (new_term.cmp_shift_sel + new_term.cmp_op_gt_shift));
            tmp *= scaling_factor;
            std::get<16>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<17, ContainerOverSubrelations>;
            auto tmp =
                (((new_term.cmp_cmp_rng_ctr_shift - new_term.cmp_cmp_rng_ctr) + FF(1)) * new_term.cmp_cmp_rng_ctr);
            tmp *= scaling_factor;
            std::get<17>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<18, ContainerOverSubrelations>;
            auto tmp = (new_term.cmp_op_gt * (new_term.cmp_cmp_rng_ctr - FF(4)));
            tmp *= scaling_factor;
            std::get<18>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<19, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_cmp_rng_ctr *
                         (((FF(1) - new_term.cmp_shift_sel) * (FF(1) - new_term.cmp_op_eq_diff_inv)) +
                          new_term.cmp_op_eq_diff_inv)) -
                        new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<19>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<20, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_a_lo_shift - new_term.cmp_b_lo) * new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<20>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<21, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_a_hi_shift - new_term.cmp_b_hi) * new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<21>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<22, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_b_lo_shift - new_term.cmp_p_sub_a_lo) * new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<22>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<23, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_b_hi_shift - new_term.cmp_p_sub_a_hi) * new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<23>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<24, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_p_sub_a_lo_shift - new_term.cmp_p_sub_b_lo) * new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<24>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<25, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_p_sub_a_hi_shift - new_term.cmp_p_sub_b_hi) * new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<25>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<26, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_p_sub_b_lo_shift - new_term.cmp_res_lo) * new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<26>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<27, ContainerOverSubrelations>;
            auto tmp = ((new_term.cmp_p_sub_b_hi_shift - new_term.cmp_res_hi) * new_term.cmp_shift_sel);
            tmp *= scaling_factor;
            std::get<27>(evals) += typename Accumulator::View(tmp);
        }
    }
};

template <typename FF> class cmp : public Relation<cmpImpl<FF>> {
  public:
    static constexpr const char* NAME = "cmp";

    static std::string get_subrelation_label(size_t index)
    {
        switch (index) {
        case 3:
            return "CMP_RES_IS_BOOL";
        case 4:
            return "CMP_OP_EQ";
        case 5:
            return "INPUT_DECOMP_1";
        case 6:
            return "INPUT_DECOMP_2";
        case 8:
            return "SUB_LO_1";
        case 9:
            return "SUB_HI_1";
        case 11:
            return "SUB_LO_2";
        case 12:
            return "SUB_HI_2";
        case 13:
            return "RES_LO";
        case 14:
            return "RES_HI";
        case 17:
            return "CMP_CTR_REL_1";
        case 18:
            return "CMP_CTR_REL_2";
        case 19:
            return "CTR_NON_ZERO_REL";
        case 20:
            return "SHIFT_RELS_0";
        case 22:
            return "SHIFT_RELS_1";
        case 24:
            return "SHIFT_RELS_2";
        case 26:
            return "SHIFT_RELS_3";
        }
        return std::to_string(index);
    }
};

} // namespace bb::Avm_vm