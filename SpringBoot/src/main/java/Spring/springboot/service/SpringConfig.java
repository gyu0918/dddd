package Spring.springboot.service;

import Spring.springboot.aop.TimeTraceAop;
import Spring.springboot.repository.*;
import jakarta.persistence.EntityManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import javax.sql.DataSource;

@Configuration
public class SpringConfig {
    private final MemberRepository memberRepository;


    @Autowired
    public SpringConfig(MemberRepository memberRepository) {
        this.memberRepository = memberRepository;
    }
    @Bean
    public MemberService memberService(){

        return new MemberService(memberRepository());
    }

   /* @Bean
    public TimeTraceAop timeTraceAop() {
        return new TimeTraceAop();
    }*/
   // private MemberRepository memberRepository() {
    }

    // @Bean
   // public MemberRepository memberRepository(){

        //return new MemoryMemberRepository();
       // return new JdbcMemberRepository(dataSource);
       // return new JdbcTemplateMemberRepository(dataSource);
         //return new JpaMemberRepository(em);
    }
}
