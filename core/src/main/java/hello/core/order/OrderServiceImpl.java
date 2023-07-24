package hello.core.order;

import hello.core.discount.DiscountPolicy;
import hello.core.discount.FixDiscountPolicy;
import hello.core.discount.RateDiscountPolicy;
import hello.core.member.Member;
import hello.core.member.MemberRepository;
import hello.core.member.MemoryMemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class OrderServiceImpl implements OrderService{
    //Order를 구현시키는데 필여한 것들
    ////////private final MemberRepository memberRepository = new MemoryMemberRepository();
    //private final DiscountPolicy discountPolicy = new FixDiscountPolicy();
    //final 은 무조건 값이 할당되어야한다.
    //private final DiscountPolicy discountPolicy = new RateDiscountPolicy();
    ////////private DiscountPolicy discountPolicy;
    private MemberRepository memberRepository;
    private DiscountPolicy discountPolicy;

    //필드 주입!
    //@Autowired private MemberRepository memberRepository;  이런식으로 Private임에도 이렇게 의존관계를 필드에서 바로 주입할수 있다.
    //@Autowired private DiscountPolicy discountPolicy;


    //수정자 주입! 이떄 필드에 final 이 없어야 한다. 또한 수정자 주입을 하게 된다면 밑에 있는 생성자 주입은 할 필요가 없다.
    @Autowired//선택적으로 의존성을 주입하거나 주입하지 않거나 컨트롤 할수 있다
    public void setMemberRepository(MemberRepository memberRepository){
        this.memberRepository = memberRepository;
    }
    @Autowired
    public void setDiscountPolicy (DiscountPolicy discountPolicy) {
        this.discountPolicy = discountPolicy;
    }

    //<생성자 주입>
    //스프링컨테이너에서 빈이 등록이 되고 각 빈마다 의존관계들이 주입이 된다. 이 2가지 과정을 거친다.
    @Autowired                  //생성자가 1개 밖에 없을 경우는 @Autowired를 설정하지 않아도 자동으로 생성자주입이 된다.
    public OrderServiceImpl(MemberRepository memberRepository, DiscountPolicy discountPolicy) {
        this.memberRepository = memberRepository;
        this.discountPolicy = discountPolicy;
    }

    @Override
    public Order createOrder(Long memberId, String itemName, int itemPrice) {
        Member member = memberRepository.findById(memberId);
        int discountPrice = discountPolicy.discount(member, itemPrice);
        return new Order(memberId, itemName, itemPrice, discountPrice);   // 이부분 왜 이렇게 해놓는 거지?
    }

    //테스트 용도
    public MemberRepository getMemberRepository() {
        return memberRepository;
    }
}
