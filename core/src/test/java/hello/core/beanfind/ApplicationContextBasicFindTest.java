package hello.core.beanfind;

import hello.core.AppConfig;
import hello.core.member.MemberService;
import hello.core.member.MemberServiceImpl;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.NoSuchBeanDefinitionException;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;

class ApplicationContextBasicFindTest {
    AnnotationConfigApplicationContext ac  = new AnnotationConfigApplicationContext(AppConfig.class);

    @Test
    @DisplayName("빈 이름 조회하기")
    void findBeanByName(){
        MemberService memberService = ac.getBean("memberService", MemberService.class);
      //  System.out.println("memberService = " + memberService);
      //  System.out.println("memberService.getClass() = " + memberService.getClass());
        assertThat(memberService).isInstanceOf(MemberServiceImpl.class);  //option + enter 로 assertions을 static화
                                                                           //static화: Assertions 안써도 assertThat사용가능
    }

    @Test
    @DisplayName("이름없이 타입으로만 조회")
    void findBeanByType (){
        MemberService memberService = ac.getBean(MemberService.class);
        assertThat(memberService).isInstanceOf(MemberServiceImpl.class);  //option + enter 로 assertions을 static화
    }

    @Test
    @DisplayName("구체 타입으로만 조회")
    void findBeanByName2 (){
        MemberService memberService = ac.getBean("memberService", MemberServiceImpl.class);
        assertThat(memberService).isInstanceOf(MemberServiceImpl.class);  //option + enter 로 assertions을 static화
    }

    //개발자는 항상 안되는 케이스도 테스트 해봐야한다.
    @Test
    @DisplayName("빈 조회가 안된다.")
    void findBeanByNameX(){
        //MemberService xxxx = ac.getBean("xxxx", MemberService.class);
        assertThrows(NoSuchBeanDefinitionException.class,
            () -> ac.getBean("xxxx", MemberService.class));
    }
}
